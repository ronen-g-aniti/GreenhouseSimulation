import numpy as np 
def generate_ugv_csv():
    ugv_components = []

    # Main Body - Centered at (0, 0, 0), dimensions: 2ft x 1ft x 0.5ft
    # Given the half-size, iterate to create the main body
    for x in np.arange(-1.0, 1.1, 0.2):
        for y in np.arange(-0.5, 0.6, 0.2):
            for z in np.arange(0, 0.6, 0.2):
                ugv_components.append((x, y, z, 0.1, 0.1, 0.1))

    # Wheels - Assume each wheel has a radius of 0.2 ft and is 0.2 ft thick
    wheel_positions = [(-0.9, -0.5, -0.2), (0.9, -0.5, -0.2), (-0.9, 0.5, -0.2), (0.9, 0.5, -0.2)]
    for wx, wy, wz in wheel_positions:
        for x in np.arange(wx-0.2, wx+0.3, 0.2):
            for y in np.arange(wy-0.2, wy+0.3, 0.2):
                ugv_components.append((x, y, wz, 0.1, 0.1, 0.1))

    # Sensor Array - Assume a simple cubic sensor array centered on the main body
    for x in np.arange(-0.2, 0.3, 0.2):
        for y in np.arange(-0.2, 0.3, 0.2):
            ugv_components.append((x, y, 0.6, 0.1, 0.1, 0.1))

    # Write to CSV
    with open('ugv_model.csv', 'w') as file:
        file.write('x,y,z,hx,hy,hz\n')
        for comp in ugv_components:
            file.write(','.join(map(str, comp)) + '\n')

generate_ugv_csv()
