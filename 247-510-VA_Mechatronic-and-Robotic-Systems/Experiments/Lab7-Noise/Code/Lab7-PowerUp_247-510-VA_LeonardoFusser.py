import numpy as np
import matplotlib.pyplot as plt


def RC_Output(t, R=10E3, C=100E-9, Vin=5.0):
    tau = R*C
    Vout = Vin*(1-np.exp(-t/tau))
    return Vout, tau

def RC_63(t, R=10E3, C=100E-9, Vin=5.0):
    tau = R*C
    tangent = t/tau
    return tangent


if __name__ == '__main__':
    #region Setup
    N = 150
    t = np.linspace(0, 10E-3, N)
    V_HTH = 4.5
    V_LTH = 1.3
    Vin = 5.0
    #endregion

    #region Simulation & Testing
    noise_pwr = 0.01
    noise = (noise_pwr**2)*np.random.randn(N)
    V, tau_value = RC_Output(t, Vin=Vin)
    V = V + noise
    RESET_idx = np.where(V<V_LTH)[0]
    RUNNING_idx = np.where(V>V_HTH)[0]
    Time_EOR = t[RESET_idx][-1]
    Time_SOR = t[RUNNING_idx][0]
    VLogic = np.zeros(len(RESET_idx))
    VLogic = Vin*np.append(VLogic, np.ones(N-len(RESET_idx)))
    #endregion

    #region Simulation plotting
    plt.subplot(2, 1, 1)
    plt.plot(t, V, 'g')
    plt.plot(t[RESET_idx], V[RESET_idx], 'r-')
    plt.plot(t[RUNNING_idx], V[RUNNING_idx], 'r-')
    plt.axvline(Time_EOR, color='b', linestyle=':')
    plt.axvline(Time_SOR, color='b', linestyle=':')
    plt.grid('on')
    plt.ylabel('Voltage')
    plt.xlabel('Time')
    plt.title('POWER-ON RESET DIAGRAM\nEnd of reset at %6.2e, $\\tau$ = %6.2e'%(Time_EOR,tau_value))

    plt.subplot(2, 1, 2)
    plt.plot(t, VLogic)
    plt.grid('on')
    plt.ylabel('Voltage')
    plt.xlabel('Time')

    plt.show()
    #endregion
