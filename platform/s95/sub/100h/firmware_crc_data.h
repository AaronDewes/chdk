/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100h_crc32[]={
    { (const char *)0xff810000,   0x393b4e, 0xca917300 }, // ROMCODE
    { (const char *)0xffc9a23c,     0xf6e4, 0x4972372c }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00H", firmware_100h_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff89548d, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
