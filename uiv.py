# CC BY-NC 2024 by Júlia Rosell Saldaña
# Use this code as you please. It's free and the main idea is that you will use it for helping people.
# The only I would like is to use the Attribution-NonCommercial Creative Commons License and remember who wrote it in the first place, but it's not important and I don't really care. I only want people to enjoy music as much as I do.

import tkinter as tk
import serial

# Configura la connexió serial
ser = serial.Serial('COM10', 9600)  # Assegura't de substituir 'COM6' pel port correcte

def send_finger_and_bow_command(finger, position):
    command = f"finger{finger}:{position}\n"
    ser.write(command.encode())

root = tk.Tk()
root.title("Autoviolí")

frame = tk.Frame(root)
frame.pack()

# Botons per controlar el dit i l'arc alhora
tk.Label(frame, text="Control del Dit i de l'Arc").pack()

# Línia de separació
tk.Label(root, text="").pack()  # Afegeix una línia buida per a la separació

# Finger 1: Sol, La, Si, Do
frame1 = tk.Frame(root)
frame1.pack()
tk.Button(frame1, text="Sol", command=lambda: send_finger_and_bow_command(1, 0)).pack(side=tk.LEFT)
tk.Button(frame1, text="La", command=lambda: send_finger_and_bow_command(1, 1)).pack(side=tk.LEFT)
tk.Button(frame1, text="Si", command=lambda: send_finger_and_bow_command(1, 2)).pack(side=tk.LEFT)
tk.Button(frame1, text="Do", command=lambda: send_finger_and_bow_command(1, 3)).pack(side=tk.LEFT)

# Línia de separació
tk.Label(root, text="").pack()  # Afegeix una línia buida per a la separació

# Finger 2: Re, Mi, Fa, Sol
frame2 = tk.Frame(root)
frame2.pack()
tk.Button(frame2, text="Re", command=lambda: send_finger_and_bow_command(2, 0)).pack(side=tk.LEFT)
tk.Button(frame2, text="Mi", command=lambda: send_finger_and_bow_command(2, 1)).pack(side=tk.LEFT)
tk.Button(frame2, text="Fa", command=lambda: send_finger_and_bow_command(2, 2)).pack(side=tk.LEFT)
tk.Button(frame2, text="Sol", command=lambda: send_finger_and_bow_command(2, 3)).pack(side=tk.LEFT)

# Línia de separació
tk.Label(root, text="").pack()  # Afegeix una línia buida per a la separació

# Finger 3: La, Si, Do, Re
frame3 = tk.Frame(root)
frame3.pack()
tk.Button(frame3, text="La", command=lambda: send_finger_and_bow_command(3, 0)).pack(side=tk.LEFT)
tk.Button(frame3, text="Si", command=lambda: send_finger_and_bow_command(3, 1)).pack(side=tk.LEFT)
tk.Button(frame3, text="Do", command=lambda: send_finger_and_bow_command(3, 2)).pack(side=tk.LEFT)
tk.Button(frame3, text="Re", command=lambda: send_finger_and_bow_command(3, 3)).pack(side=tk.LEFT)

# Línia de separació
tk.Label(root, text="").pack()  # Afegeix una línia buida per a la separació

# Finger 4: Mi, Fa, Sol, La
frame4 = tk.Frame(root)
frame4.pack()
tk.Button(frame4, text="Mi", command=lambda: send_finger_and_bow_command(4, 0)).pack(side=tk.LEFT)
tk.Button(frame4, text="Fa", command=lambda: send_finger_and_bow_command(4, 1)).pack(side=tk.LEFT)
tk.Button(frame4, text="Sol", command=lambda: send_finger_and_bow_command(4, 2)).pack(side=tk.LEFT)
tk.Button(frame4, text="La", command=lambda: send_finger_and_bow_command(4, 3)).pack(side=tk.LEFT)

# Línia de separació
tk.Label(root, text="").pack()  # Afegeix una línia buida per a la separació

root.mainloop()