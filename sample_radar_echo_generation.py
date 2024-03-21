import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Load UGV geometry
ugv_df = pd.read_csv('ugv_model.csv', header=None, skiprows=1)
ugv_df.columns = ['x', 'y', 'z', 'hx', 'hy', 'hz']

# Assume a simple radar map resolution
radar_resolution = (100, 100, 15)  # Adjust based on your requirements
radar_map = np.zeros(radar_resolution)

# Define a function to calculate reflectivity based on UGV geometry
def calculate_reflectivity(x, y, z):
    # Example: Assign higher reflectivity to points above ground level
    if z > 0:
        return 0.8  # High reflectivity
    else:
        return 0.2  # Low reflectivity

# Apply the calculate_reflectivity function to each row in the DataFrame
ugv_df['reflectivity'] = ugv_df.apply(lambda row: calculate_reflectivity(row['x'], row['y'], row['z']), axis=1)

# Simulate radar echoes by marking UGV cubes in the radar map with reflectivity
for index, row in ugv_df.iterrows():
    x, y, z = int(row['x']), int(row['y']), int(row['z'])
    reflectivity = row['reflectivity']  # Reflectivity value based on UGV geometry
    # Mark the radar echo intensity based on reflectivity
    radar_map[x, y, z] = reflectivity

# Add Gaussian noise
noise = np.random.normal(0, 0.1, radar_map.shape)  # Mean 0, std 0.1 (adjust as needed)
radar_map_noisy = radar_map + noise

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Choose a slice or projection method, here we sum along the z-axis
radar_projection = np.sum(radar_map_noisy, axis=2)

x, y = np.meshgrid(range(radar_projection.shape[0]), range(radar_projection.shape[1]))

# Plot using scatter, considering only points with intensity above a threshold
threshold = 0.5  # Adjust based on your noise level and intensity values
mask = radar_projection > threshold
ax.scatter(x[mask], y[mask], radar_projection[mask])

plt.show()
