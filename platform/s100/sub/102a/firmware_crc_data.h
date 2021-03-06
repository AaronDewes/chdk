/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_102a_crc32[]={
    { (const char *)0xff000000,   0x4524c6,  0x5a4aac8 }, // ROMCODE
    { (const char *)0xff64becc,    0x12fa8, 0xa2ae236a }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.02A", firmware_102a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff0908b9, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
