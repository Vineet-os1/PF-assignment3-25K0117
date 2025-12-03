#include <stdio.h>

int calculateFuel(int fuel, int consumption, int recharge,
                  int solarBonus, int planet, int totalPlanets)
{
    if (fuel <= 0 || planet > totalPlanets) {
        return fuel > 0; // 1 = success, 0 = fail
    }
    fuel = fuel - consumption;

    if (fuel <= 0) {
        printf("Planet %d: Fuel Remaining = 0 (Mission Failed)\n", planet);
        return 0;
    }
    fuel = fuel + recharge;
    if (planet % 4 == 0) {
        fuel = fuel + solarBonus;
    }
    printf("Planet %d: Fuel Remaining = %d\n", planet, fuel);
    return calculateFuel(fuel, consumption, recharge,
                         solarBonus, planet + 1, totalPlanets);
}

int main()
{
    int fuel = 500;
    int consumption = 70;
    int recharge = 20;
    int solarBonus = 50;
    int totalPlanets = 10;

    int result = calculateFuel(fuel, consumption, recharge,
                               solarBonus, 1, totalPlanets);

    if (result == 1) {
        printf("Mission Status: Success\n");
    } else {
        printf("Mission Status: Failed\n");
    }

    return 0;
}
