![logo](https://user-images.githubusercontent.com/25873978/47947397-7c18f200-defa-11e8-9943-9d10470bd2b9.png)

# An Open-Source Simulator for Surface Plasmon Resonance Applications
## Description:

We present our free, open-source simulator for Surface Plasmon Resonance (SPR) applications implemented in C++ language.

## Characteristics:

* Number of Layers: N layers;
* Configuration: Otto (a), Kretschmann (b) and Optical Fiber (c);
* License: Open-Source;
* Language: C++;
* Operation: Angular Interrogation Mode (AIM) and Wavelength Interrogation Mode (WIM).

<p align="center">
  <img src="https://user-images.githubusercontent.com/25873978/51500991-58f23600-1db7-11e9-98a1-1cbae5c7e811.png">
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/25873978/55975343-c8115500-5c57-11e9-978e-ba597d807e35.png">
</p>

## Prerequisites:

* G++ Compile (C++11 version);
* Linux Terminal to compile Sim-SPR;
* Git subversion;
* GNUplot to plot waveforms.

## Getting Started (Download Sim-SPR):
```
$ git clone https://github.com/eltonbrasil/SimSPR.git 
```

## Running Applications

You can compile Sim-SPR using Makefile technique, given by following commands:

### First, go to testbench on Sim-SPR folder as:
```
$ cd testbench
```
### If you need some help:
```
$ make help
```
### To compile your testbench using G++ tools:
```
$ make test
```
### To run your simulation:
```
$ make run
```
> After to run your simulation, you will be presented to the "Welcome to Sim-SPR", in which you can choose the SPR sensor configuration.

### To clean unnecessary files:
```
$ make clean
```
> This command also clean hidden files, using rm -i .*

## Full Sequence Diagram of the Sim-SPR

<p align="center">
  <img src="https://user-images.githubusercontent.com/25873978/56314752-eed1fe80-6123-11e9-8f78-4726654d7df6.png">
</p>

## Sim-SPR Current Status and Future Improvements

- [x] Kretschmann and Otto configurations
- [X] Optical Fiber
- [x] Laser Light Source
- [x] N layers
- [x] Angular Interrogation Mode: Kretschmann, Otto and optical fiber configurations
- [x] Wavelength Interrogation Mode: only for optical fiber using gold as metal layer
- [x] Sensitivity Angular Interrogation Mode
- [ ] Sensitivity Wavelength Interrogation Mode
- [ ] LED Light Source
- [ ] Anisotropy
- [ ] Graphical Interface

## Sim-SPR

For more details, please refer to our article: [Sim-SPR: an Open-Source Surface Plasmon Resonance Simulator for Academic and Industrial Purposes](https://link.springer.com/article/10.1007%2Fs11468-019-00970-5)

## Author

* **Elton Brasil da Costa** - [Curriculum Lattes (Portuguese)](http://buscatextual.cnpq.br/buscatextual/visualizacv.do?id=K4459901A6)
* Contact: elton.costa@ee.ufcg.edu.br
