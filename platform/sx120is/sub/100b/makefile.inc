#31E0
PLATFORMID=12768

PLATFORMOS=dryos

# Force ARAM on, and load CHDK in ARAM
override OPT_ARAM_MALLOC=1
override OPT_CHDK_IN_ARAM=1

# Set up size variables for AgentRAM
ARAM_HEAP_START=0x34e000
ARAM_HEAP_SIZE=0x32000

ifdef OPT_CHDK_IN_ARAM
MEMISOSTART=$(ARAM_HEAP_START)
else
MEMISOSTART=0x10A6AC
endif

ROMBASEADDR=0xFFC00000
NEED_ENCODED_DISKBOOT=3

NEED_ENCODED_DISKBOOT=3
KEYSYS=d4

PLATFORMOSVER=39
