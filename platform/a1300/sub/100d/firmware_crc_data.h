/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100d_crc32[]={
    { (const char *)0xff810000,   0x2ff570, 0x2dcd2b8c },
    { (const char *)0xffc012e0,     0xf5d4, 0x136877b0 },
    { (const char *)0xffbf5c38,     0xb6a8, 0x89e84519 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00D", firmware_100d_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff87d84d, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
