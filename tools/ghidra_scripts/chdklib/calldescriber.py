# License: GPL
#
# Copyright 2020-2021 reyalp (at) gmail.com
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# with CHDK. If not, see <http://www.gnu.org/licenses/>.

# Ghidra needs this in a module to access standard stuff
from __main__ import *

# to set verbosity
import chdklib.logutil
from chdklib.logutil import infomsg, warn
from chdklib.defines_loader import PropsetData
from chdklib.leventutil import get_levent_data

from chdklib.regsanalyzer import RegsAnalyzer

class CallDescriber(object):
    def __init__(self, funcdesc):
        self.ra = RegsAnalyzer(currentProgram, monitor)
        self.funcdesc = funcdesc

    def describe_call(self,addr,fname):
        # TODO could pick up func name from Ghidra by getting target of b/bl at addr
        fdesc = self.funcdesc.get(fname)
        if not fdesc:
            raise ValueError('unknown func %s'%(fname))

        reg_ids = sorted(list(fdesc))
        regs = self.ra.getRegs(reg_ids,addr)
        if not regs:
            # worth printing since user can potentially fix (may want to supress though)
            infomsg(0,'%s %s Call not in function?\n'%(addr,fname))
            return

        results = []
        for r in reg_ids:
            results.append(self.describe_reg(regs[r],fdesc[r]))

        return results

    def describe_reg(self,reg,rdesc):
        arg_type = rdesc['type']
        res = {
            'type':arg_type,
        }
        if reg is None:
            res['desc'] = 'unk'
            res['val'] = None
            return res


        res['val'] = reg.getValue()

        if arg_type == 'INT':
            if reg.isRegisterRelativeValue():
                infomsg(2,'%s reg rel INT %s for %s\n'%(addr,r,fname))
                res['desc'] = 'unk'
            else:
                res['desc'] = str(reg.getValue())
        # TODO strings and things
        else:
            if reg.isRegisterRelativeValue():
                res['desc'] = str(reg.getRelativeRegister()) + ' %#x'%(reg.getValue())
            else:
                res['desc'] = '%#x'%(reg.getValue())

        return res

prop_funcdesc = {
    'GetPropertyCase':{
        'r0':{
            'type':'PROPCASE_ID',
        },
        'r1':{
            'type':'OUT_PTR',
        },
        'r2':{
            'type':'INT',
        },
    },
    'SetPropertyCase':{
        'r0':{
            'type':'PROPCASE_ID',
        },
        'r1':{
            'type':'IN_PTR',
        },
        'r2':{
            'type':'INT',
        },
    },
}

class PropCallDescriber(CallDescriber):
    def __init__(self,filename):
        super(PropCallDescriber,self).__init__(prop_funcdesc)
        self.pd = PropsetData(filename)

    def describe_reg(self,reg,rdesc):
        res = super(PropCallDescriber,self).describe_reg(reg,rdesc)

        if res['type'] == 'PROPCASE_ID':
            res['prop_name'] = ''
            if res['val'] is None:
                return res

            if reg.isRegisterRelativeValue():
                infomsg(2,'%s reg rel PROPCASE_ID %s for %s\n'%(addr,r,fname))
                res['desc'] = 'unk'
            else:
                prop_id = reg.getValue()
                if prop_id in self.pd.by_id:
                    res['prop_name'] = self.pd.by_id.get(prop_id,str(prop_id))
                    res['desc'] = '%s (%d)'%(res['prop_name'],prop_id)
                else:
                    res['desc'] = str(prop_id)

        return res

levent_funcdesc = {
    'PostLogicalEventToUI':{
        'r0':{
            'type':'LEVENT_ID',
        },
        'r1':{
            'type':'INT',
        },
    },
    'PostLogicalEventForNotPowerType':{
        'r0':{
            'type':'LEVENT_ID',
        },
        'r1':{
            'type':'INT',
        },
    },
    'IsControlEventActive_FW':{
        'r0':{
            'type':'LEVENT_ID',
        },
    },
    'SetLogicalEventActive':{
        'r0':{
            'type':'LEVENT_ID',
        },
        'r1':{
            'type':'INT',
        },
    },
}

class LeventCallDescriber(CallDescriber):
    def __init__(self):
        super(LeventCallDescriber,self).__init__(levent_funcdesc)
        self.ld = get_levent_data()

    def describe_reg(self,reg,rdesc):
        res = super(LeventCallDescriber,self).describe_reg(reg,rdesc)

        if res['type'] == 'LEVENT_ID':
            res['levent_name'] = ''
            if res['val'] is None:
                return res

            if reg.isRegisterRelativeValue():
                infomsg(2,'%s reg rel LEVENT_ID %s for %s\n'%(addr,r,fname))
                res['desc'] = 'unk'
            else:
                levent_id = reg.getValue()
                if levent_id in self.ld['by_id'] and self.ld['by_id'][levent_id]['name'] != '':
                    res['levent_name'] = self.ld['by_id'][levent_id]['name']
                    res['desc'] = '%s (%d)'%(res['levent_name'],levent_id)
                else:
                    res['desc'] = str(levent_id)

        return res

