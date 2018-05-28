#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parser.h"
#include "count_points.h"
#include "point.h"
#include "mainwindow.h"

static const int ok = 0;

int math_part(char *fileName, struct Point **points,  int *num_points, struct Polygon **polygons, int *num_polygons)
{
    FILE *f;
    int error = ok;

    f = fopen(fileName, "r");

    if(!f)
        std::cout << "Can't open file";
    else
    {
        count(num_points,f, 'v');

        fclose(f);
        f = fopen(fileName, "r");
        *points = new struct Point[*num_points];
        error = parser_points(*points, f);

        fclose(f);
        f = fopen(fileName, "r");
        count(num_polygons, f, 'f');

        fclose(f);
        f = fopen(fileName, "r");
        *polygons = new struct Polygon[*num_polygons];
        error = parser_polygons(*polygons, f);
    }

    return error;
}
