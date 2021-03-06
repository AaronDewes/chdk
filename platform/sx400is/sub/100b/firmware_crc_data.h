/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xff810000,   0x3e07a8, 0x15ef4a8c }, // ROMCODE
    { (const char *)0xffd46d78,    0x1d2ec,  0x9450fd7 }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00B", firmware_100b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff89f685, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
