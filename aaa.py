import numpy as np
import math

# Cost function to calculate total cost based on number of slots and waiting time penalty
def calculate_total_cost(num_slots, wq, cost_per_slot, waiting_time_penalty):
    """
    Calculate the total cost based on number of slots and waiting time.
    
    :param num_slots: Number of slots available
    :param wq: Average waiting time per vehicle (in hours)
    :param cost_per_slot: Cost for adding one slot
    :param waiting_time_penalty: Penalty cost per hour of waiting time
    :return: Total cost
    """
    slot_cost = num_slots * cost_per_slot
    waiting_cost = wq * waiting_time_penalty
    total_cost = slot_cost + waiting_cost
    return total_cost

# M/M/c Queuing Model (modified to return waiting time)
def mmc_queue(arrival_rate, service_rate, num_slots):
    """
    Calculate the queuing metrics using M/M/c model.
    
    :param arrival_rate: Average arrival rate (λ) - vehicles per hour
    :param service_rate: Average service rate per slot (μ) - swaps per hour per slot
    :param num_slots: Number of available slots (c)
    :return: Average waiting time in queue (Wq)
    """
    
    # Utilization factor ρ (traffic intensity)
    rho = arrival_rate / (num_slots * service_rate)
    
    # System is stable only when ρ < 1
    if rho >= 1:
        return float('inf')  # Return infinite waiting time if system is unstable
    
    # Calculate probability of zero vehicles in the system (P0)
    def calculate_p0():
        sum_terms = sum([(arrival_rate / service_rate)**n / math.factorial(n) for n in range(num_slots)])
        p0 = (sum_terms + ((arrival_rate / service_rate) ** num_slots) / (math.factorial(num_slots) * (1 - rho))) ** -1
        return p0
    
    p0 = calculate_p0()
    
    # Average number of vehicles in the queue (Lq)
    lq = (p0 * ((arrival_rate / service_rate) ** num_slots) * rho) / (math.factorial(num_slots) * ((1 - rho) ** 2))
    
    # Average time a vehicle spends in the queue (Wq)
    wq = lq / arrival_rate
    
    return wq  # Return only the waiting time for optimization

# Optimization function
def optimize_slots(arrival_rate, service_rate, min_slots, max_slots, cost_per_slot, waiting_time_penalty):
    """
    Optimize the number of slots and minimize total cost based on waiting time and slot cost.
    
    :param arrival_rate: Arrival rate (vehicles per hour)
    :param service_rate: Service rate per slot (swaps per hour)
    :param min_slots: Minimum number of slots to consider
    :param max_slots: Maximum number of slots to consider
    :param cost_per_slot: Cost per slot
    :param waiting_time_penalty: Penalty per hour of waiting time
    :return: Optimal number of slots and total cost
    """
    
    optimal_slots = min_slots
    optimal_cost = float('inf')
    optimal_wq = float('inf')
    
    # Try different number of slots and calculate total cost
    for num_slots in range(min_slots, max_slots + 1):
        wq = mmc_queue(arrival_rate, service_rate, num_slots)
        total_cost = calculate_total_cost(num_slots, wq, cost_per_slot, waiting_time_penalty)
        
        # Update optimal values if a lower cost is found
        if total_cost < optimal_cost:
            optimal_cost = total_cost
            optimal_slots = num_slots
            optimal_wq = wq
    
    return optimal_slots, optimal_wq, optimal_cost

# Parameters
arrival_rates = [15, 20, 25]  # Varying arrival rates (vehicles per hour)
service_rates = [4, 5, 6]     # Varying service rates (swaps per hour per slot)
min_slots = 5                 # Minimum number of slots to consider
max_slots = 15                # Maximum number of slots to consider
cost_per_slot = 5000          # Cost of adding one slot (in currency units)
waiting_time_penalty = 1000   # Penalty per hour of waiting time (in currency units)

# Optimize for each scenario
for arrival_rate in arrival_rates:
    for service_rate in service_rates:
        optimal_slots, optimal_wq, optimal_cost = optimize_slots(
            arrival_rate, service_rate, min_slots, max_slots, cost_per_slot, waiting_time_penalty
        )
        print(f"Arrival Rate: {arrival_rate} vehicles/hour, Service Rate: {service_rate} swaps/hour")
        print(f"Optimal Number of Slots: {optimal_slots}")
        print(f"Optimal Waiting Time (Wq): {optimal_wq:.4f} hours")
        print(f"Total Cost: {optimal_cost:.2f}\n")
