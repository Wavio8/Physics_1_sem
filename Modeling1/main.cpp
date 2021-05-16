#include <iostream>
#include <cmath>

using namespace std;

auto const G = 6.6743015 * pow(10, -11);

void mass_change(int &m_oil, int v_oil, int &m_rocket) {
    m_oil -= v_oil;
    m_rocket -= v_oil;
}

void radius_change(double &radius, double x, double y) {
    radius = sqrt(pow(x, 2) + pow(y, 2));
}

void gravity_attraction_change(int m_earth, int m_rocket, double &gravity_pull, double radius) {
    if (radius != 0)
        gravity_pull = G * m_earth * m_rocket / pow(radius, 2);
}

void speed_change(double &v_x, double &v_y, double gravity_pull, double angle, int m_rocket, int v_gas, int v_oil) {
    v_x += sin(angle) * v_gas * v_oil / double(m_rocket);
    v_y += cos(angle) * v_gas * v_oil / double(m_rocket);
    v_y -= gravity_pull;
}

void angle_change(double &angle, double v_x, double v_y) {
    angle = atan(v_y / v_x);
}

void coordinates_change(double &x, double &y, double v_x, double v_y) {
    x += v_x;
    y += v_y;
}

int main() {
    double angle;
    int m_rocket;
    int m_oil;
    int V_GAS;
    int V_OIL;
    int M_EARTH;
    cin >> angle;
    cin >> m_rocket;
    cin >> m_oil;
    cin >> V_GAS;
    cin >> V_OIL;
    cin >> M_EARTH;
    angle *= M_PI / 180;
    int time = 0;
    double gravity_pull = 0;
    double radius = 0;
    double x = 0;
    double y = 0;
    double v_x = 0;
    double v_y = 0;
    while (true) {
        if ((y > 0) or (time == 0)) {
            cout << "Time: " << time << " seconds" << endl;
            cout << "Coordinates: " << x << " " << y << endl;
            cout << "Speed x: " << v_x << endl;
            cout << "Speed y: " << v_y << endl;
            cout << "Module speed_change : " << pow(pow(v_x, 2) + pow(v_y, 2), 0.5) << endl;
            cout << "Oil mass: " << m_oil << endl;
            if (m_oil == 0)
                break;
            time++;
            mass_change(m_oil, V_OIL, m_rocket);
            radius_change(radius, x, y);
            gravity_attraction_change(M_EARTH, m_rocket, gravity_pull, radius);
            speed_change(v_x, v_y, gravity_pull, angle, m_rocket, V_GAS, V_OIL);
            angle_change(angle, v_x, v_y);
            coordinates_change(x, y, v_x, v_y);
        } else {
            cout << "Oil - yes, Rocket - no";
            break;
        }

    }

    return 0;
}
