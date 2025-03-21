#pragma once

namespace offsets {
    constexpr auto ref_def_ptr = 0x157821A0;
    constexpr auto name_array = 0x1578E790;
    constexpr auto name_array_list = 0x4C70;
    constexpr auto camera_base = 0x12C7DEA0;
    constexpr auto camera_pos = 0x1D8;
    constexpr auto local_index = 0x4CAE0;
    constexpr auto local_index_pos = 0x204;
    constexpr auto recoil = 0x4CE68;
    constexpr auto game_mode = 0x15280D58;
    constexpr auto weapon_definitions = 0x12D43570;
    constexpr auto distribute = 0x17E9ECF8;
    constexpr auto visible_offset = 0xA70;
    constexpr auto visible = 0x6423770;
    namespace player {
        constexpr auto size = 0x60C0;
        constexpr auto valid = 0x10E4;
        constexpr auto pos = 0xF50;
        constexpr auto team = 0x5E38;
        constexpr auto stance = 0x11C;
        constexpr auto weapon_index = 0x5ED8;
        constexpr auto dead_1 = 0x5FE0;
        constexpr auto dead_2 = 0xD34;
    }
    namespace bone {
        constexpr auto bone_base = 0x20544;
        constexpr auto size = 0x150;
    }
}