import pandas as pd
import matplotlib.pyplot as plt

def plot_projectile():
    df = pd.read_csv("data/projectile.csv")
    plt.plot(df["x"], df["y"])
    plt.xlabel("x (m)")
    plt.ylabel("y (m)")
    plt.title("Projectile Motion with Drag")
    plt.grid(True)
    plt.show()

def plot_pendulum():
    df = pd.read_csv("data/pendulum.csv")
    plt.plot(df["theta"], df["omega"])
    plt.xlabel("Angle (rad)")
    plt.ylabel("Angular Velocity (rad/s)")
    plt.title("Phase Space: Simple Pendulum")
    plt.grid(True)
    plt.show()

def plot_oscillator():
    df = pd.read_csv("data/oscillator.csv")
    plt.plot(df["x"], df["v"])
    plt.xlabel("Position (m)")
    plt.ylabel("Velocity (m/s)")
    plt.title("Phase Space: Damped Harmonic Oscillator")
    plt.grid(True)
    plt.show()