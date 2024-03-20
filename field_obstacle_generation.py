import csv

# Define obstacle parameters
# Each obstacle is defined by its bottom left corner, length (l), width (w), and height (h) in feet
obstacles = [
    {"corner": (10, 10, 0), "l": 15, "w": 15, "h": 5},  # First obstacle
    {"corner": (30, 30, 0), "l": 20, "w": 15, "h": 10}, # Second obstacle
    {"corner": (50, 10, 0), "l": 15, "w": 20, "h": 15}  # Third obstacle
]

def generate_obstacle_course_csv(file_name):
    with open(file_name, mode='w', newline='') as file:
        writer = csv.writer(file)
        # Write the header row
        writer.writerow(['x', 'y', 'z', 'hx', 'hy', 'hz'])

        # Loop through each obstacle and discretize it into unit cubes
        for obstacle in obstacles:
            corner = obstacle["corner"]
            for x in range(corner[0], corner[0] + obstacle["l"]):
                for y in range(corner[1], corner[1] + obstacle["w"]):
                    for z in range(corner[2], corner[2] + obstacle["h"]):
                        # Write each unit cube to the CSV
                        # Note: In this case, hx, hy, and hz are always 0.5 to represent half the length of the unit cube's side
                        writer.writerow([x + 0.5, y + 0.5, z + 0.5, 0.5, 0.5, 0.5])

# File name of the CSV to be generated
file_name = 'obstacle_course.csv'

# Generate the CSV file
generate_obstacle_course_csv(file_name)

print(f"CSV file '{file_name}' has been generated.")
