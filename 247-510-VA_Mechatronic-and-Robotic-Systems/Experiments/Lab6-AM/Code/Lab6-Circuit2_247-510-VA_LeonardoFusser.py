import numpy as np
import matplotlib.pyplot as plt

#region Set up simulation parameters.
fc = 1E3
fs = 1E2
Vc = 1
Vn = 0.2
Vs = 0.5
N = 500
t = np.linspace(0, 10E-3, N)
#endregion
#region Perform simulation.
carrier = Vc*np.sin(2*np.pi*fc*t)
signal = Vs*np.sin(2*np.pi*fs*t)
noise = Vn*np.random.randn(N)
AM_SIGNAL = signal*carrier
AM_SIGNAL_N = signal*carrier+noise
#endregion
#region Plot simulation results.
plt.subplot(2, 2, 1)
plt.plot(t, carrier, '--', label='Carrier')
plt.plot(t, noise, label='Noise')
plt.legend()
plt.title('Carrier Signal (%6.2fV, f=%6.2fHz )'%(Vc, fc))
plt.xlabel('Time (Seconds)')
plt.ylabel('Amplitude (Volts)')

plt.subplot(2, 2, 2)
plt.hist(noise, bins=20)
plt.title('Noise Distribution')

plt.subplot(2, 2, 3)
plt.plot(t, AM_SIGNAL, 'g', label='Signal and Carrier')
plt.plot(t, signal, 'r:', label='Signal Envelope')
plt.legend()
plt.plot(t, -signal, 'r:')
plt.title('AM Signal')
plt.xlabel('Time (Seconds)')
plt.ylabel('Amplitude (Volts)')

plt.subplot(2, 2, 4)
plt.plot(t, AM_SIGNAL_N, 'b')
plt.title('Simulated AM Signal')
plt.xlabel('Time (Seconds)')
plt.ylabel('Amplitude (Volts)')

plt.show()
#endregion
