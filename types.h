#pragma once

enum color
{
    RED,
    BLUE,
    GREY
};
typedef enum color color;

typedef enum
{
    IA,
    HUMAN
} hIA;

color opp(color c);

typedef struct
{
    int x;
    int y;
} cords;
