// This file should not be modified.

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

color opp(color c)
{
  if (c == RED)
    return BLUE;
  else
    return RED;
}
