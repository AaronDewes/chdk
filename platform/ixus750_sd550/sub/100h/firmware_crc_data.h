/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100h_crc32[]={
    { (const char *)0xff810000,   0x2e9c80, 0x9dae0a9d }, // ROMCODE, RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00H", firmware_100h_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff81addd, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    1,  // block_count
};
