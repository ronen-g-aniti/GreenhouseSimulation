import matplotlib.pyplot as plt
import numpy as np
import csv
from mpl_toolkits.mplot3d import Axes3D

def visualize_ugv(csv_filename="ugv_model.csv"):
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')

    with open(csv_filename, 'r') as file:
        reader = csv.reader(file)
        next(reader)  # Skip the header row
        for row in reader:
            x, y, z, hx, hy, hz = map(float, row)
            # Adjust the position to start from the corner instead of the center for visualization
            ax.bar3d(x-hx, y-hy, z, hx*2, hy*2, hz*2, color='green', alpha=0.5)

    ax.set_title('UGV Model Visualization')
    plt.show()

visualize_ugv()  # Ensure to use the correct CSV filename
