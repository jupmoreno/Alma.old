# KI α

KI is based on x64BareBones wich is a basic setup to develop operating systems for the Intel 64 bits architecture.

The final goal of x64BareBones's project is to provide an entry point for a kernel and the possibility to load extra binary modules separated from the main kernel.

Please read "Manual de Usuario.pdf" for the usage manual and "Informe.pdf" for more information about KI.

## Requisites

### General

This project needs the following packages:

`nasm qemu gcc make`

### Mac OS

1) Install QEMU

`brew install qemu`

2) Optional: Install NASM

`brew install nasm`

2) Optional: Install the newest version of MAKE

`brew install make`

## Usage

From the project's directory run:

`make run`

Makes Toolchain, cleans everything, makes all, and runs

## Credits: 
- x64BareBones (base project): 
	- Author: Rodrigo Rearden (RowDaBoat) 
	- Collaborator: Augusto Nizzo McIntosh

- KI (kernel modifications): 
	- Author: Matías Nicolás Comercio Vázquez 
	- Author: Juan Moreno