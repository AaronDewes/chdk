/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101g_crc32[]={
    { (const char *)0xff810000,   0x39014a, 0x4ea5cb8a },
    { (const char *)0xffc8ab88,     0xeb9c, 0x818954a6 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01G", firmware_101g_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff894efd, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
