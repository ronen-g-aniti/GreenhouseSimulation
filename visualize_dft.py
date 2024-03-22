import numpy as np
import matplotlib.pyplot as plt
import csv

# Load data from CSV
data = np.genfromtxt('dftResults.csv', delimiter=',', dtype=complex)

# Assuming the CSV has two columns: real and imaginary parts
real_parts = data[:, 0]
imaginary_parts = data[:, 1]

# Convert real and imaginary parts to a complex number array
complex_numbers = real_parts + 1j * imaginary_parts

# Calculate magnitudes and phases of the complex numbers
magnitudes = np.abs(complex_numbers)
phases = np.angle(complex_numbers)

# Frequency bins, replace with appropriate values for your case
frequencies = np.arange(len(complex_numbers))

# Plotting the magnitude spectrum
plt.figure(figsize=(14, 6))
plt.subplot(1, 2, 1)
plt.stem(frequencies, magnitudes, 'b', markerfmt=" ", basefmt=" ")
plt.title('Magnitude Spectrum')
plt.xlabel('Frequency Bin')
plt.ylabel('Magnitude')

# Plotting the phase spectrum
plt.subplot(1, 2, 2)
plt.stem(frequencies, phases, 'r', markerfmt=" ", basefmt=" ")
plt.title('Phase Spectrum')
plt.xlabel('Frequency Bin')
plt.ylabel('Phase (radians)')

plt.tight_layout()
plt.show()
