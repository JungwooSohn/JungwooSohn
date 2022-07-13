#include <iostream>
#include <cmath>

class Point {

    public:
        int x, y;
        Point(int pos_x, int pos_y) {
            x = pos_x;
            y = pos_y;
        }
};

class Geometry {
    private:
        Point* point_array[100];
        int num_points;
    
    
    public:
        Geometry() {
            num_points = 0;
        }

        void AddPoint(const Point &point) {
            point_array[num_points++] = new Point(point.x, point.y);

        }

        void PrintDistance() {
            for (int i = 0; i < num_points; i++) {
                for (int j = 0; j < num_points; j++) {
                    if (j != i) {
                        std::cout << "(" << point_array[i]->x << ", "<< point_array[i]->y << ")" << " 와 " << "(" << point_array[j]->x << ", "<< point_array[j]->y << ")" << "사이의 거리: " << sqrt(pow(point_array[i]->x - point_array[j]->x, 2) + pow((point_array[i]->y - point_array[j]->y), 2)) << std::endl;
                    }
                }
            }
        }

        double GetIncline(const Point &point1, const Point &point2) {
            return (double) point2.y - point1.y / (double) point2.x - point1.x;
        }

        void PrintNumMeets() {
            
        }


};


int main(void) {

    Geometry geometry;
    Point point1(1, 3);
    Point point2(2, 8);
    Point point3(1, 5);
    geometry.AddPoint(point1);
    geometry.AddPoint(point2);
    geometry.AddPoint(point3);

    geometry.PrintDistance();
    

    return 0;
}