#pragma once

#include <algorithm>

namespace therock::fuel {

struct FuelInput {
    double dt_seconds = 0.0;
    double speed_kmh = 0.0;
    double rpm = 0.0;
    double engine_load = 0.0; // 0.0 - 1.0
};

struct FuelState {
    double capacity_liters = 60.0;
    double fuel_liters = 60.0;
    double consumed_liters = 0.0;
};

class FuelTank {
public:
    explicit FuelTank(double capacity_liters);

    void reset();

    void refuel(double liters);

    void update(const FuelInput& input);

    double fuel() const noexcept;
    double capacity() const noexcept;
    double fuel_fraction() const noexcept;
    double consumed() const noexcept;

private:
    double consumption_rate(const FuelInput& input) const noexcept;

    FuelState state_;
};

} // namespace therock::fuel