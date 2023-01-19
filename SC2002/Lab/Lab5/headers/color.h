#ifndef ZOO_COLOR_H
#define ZOO_COLOR_H

enum COLOR
{
    Green,
    Blue,
    White,
    Black,
    Brown
};

inline const char *ToString(COLOR c)
{
    switch (c)
    {
    case Green:
        return "Green";
    case Blue:
        return "Blue";
    case White:
        return "White";
    case Black:
        return "Black";
    case Brown:
        return "Brown";
    default:
        return "[Unknown COLOR]";
    }
}

#endif