#include <iostream>
#include <cmath>

using namespace std;

void acceleration_change(double &a, double u_plates, double r_outer, double r_interior, double q_EL, double M_EL,
                         double r_now) {
    a = q_EL * u_plates / (log(r_outer / r_interior) * M_EL * r_now);
}

void speed_change(double a, double &v_y) {
    v_y += a;
}

void radius_change(double v_y, double &r_now) {
    r_now += v_y;
}

void coordinates_change(double &x, double &y, double v_x, double r_now, double r_interior) {
    y = r_now - r_interior;
    x += v_x;
}

int main() {
    double u_plates;
    double r_outer;
    double distance_plates;
    double l;
    double e;
    double v;

    cin >> u_plates;
    cin >> r_outer >> distance_plates;
    cin >> l;
    cin >> e;
    cin >> v;


    int time = 0;
    double x = 0;
    double y = distance_plates / 2;
    double v_x = v;
    double v_y = 0;
    double a = 0;
    double M_EL = 9.11e-31;
    double q_EL = 1.6e-19;

    double r_interior = r_outer - distance_plates;
    double r_now = (r_outer + r_interior) / 2;


    while ((r_now >= r_interior) && (r_now <= r_outer) && (x <= l)) {
        cout << "Time: " << time << " seconds" << endl;
        cout << "Coordinates: " << x << " " << y << endl;
        cout << "Speed y: " << v_y << endl;
        cout << "Module speed_change : " << pow(pow(v_x, 2) + pow(v_y, 2), 0.5) << endl;
        cout << "Acceleration: " << a << endl;
        cout << endl;

        acceleration_change(a, u_plates, r_outer, r_interior, q_EL, M_EL, r_now);
        speed_change(a, v_y);
        radius_change(v_y, r_now);
        coordinates_change(x, y, v_x, r_now, r_interior);

        time++;
    }


    return 0;
}
