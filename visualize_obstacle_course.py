import csv
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def plot_obstacle_course(csv_file):
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')

    with open(csv_file, mode='r') as file:
        reader = csv.DictReader(file)
        for row in reader:
            # Extract the center position and half-size of each cube
            x, y, z = float(row['x']), float(row['y']), float(row['z'])
            hx, hy, hz = float(row['hx']), float(row['hy']), float(row['hz'])

            # Calculate the corner position of the cube (bottom left corner)
            corner_x, corner_y, corner_z = x - hx, y - hy, z - hz

            # Plot each cube
            ax.bar3d(corner_x, corner_y, corner_z, hx * 2, hy * 2, hz * 2, alpha=0.8, color="red")

    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')
    ax.set_title('Obstacle Course Visualization')

    plt.show()

# File name of the CSV containing the obstacle course data
csv_file = 'obstacle_course.csv'

# Plot the obstacle course
plot_obstacle_course(csv_file)