#ifndef TYPES_H
#define TYPES_H

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

#endif
