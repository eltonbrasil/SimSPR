![logo](https://user-images.githubusercontent.com/25873978/47947397-7c18f200-defa-11e8-9943-9d10470bd2b9.png)

# An Open-Source Simulator for Surface Plasmon Resonance Applications
## Description:

We present our free, open-source simulator for Surface Plasmon Resonance (SPR) applications implemented in C++ language.

## Characteristics:

* Number of Layers: N layers;
* Configuration: Otto (a), Kretschmann (b) and Optical Fiber;
* License: Open-Source;
* Language: C++;
* Operation: Angular Interrogation Mode (AIM).

<p align="center">
  <img src="https://user-images.githubusercontent.com/25873978/51500991-58f23600-1db7-11e9-98a1-1cbae5c7e811.png">
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
### After to run your simulation, you will be presented to the "Welcome to Sim-SPR", in which you can choose the SPR sensor configuration, presented as:

<p align="center">
  <img src="https://user-images.githubusercontent.com/25873978/55974570-efffb900-5c55-11e9-9978-1d02ba00ec02.png">
</p>

### To clean unnecessary files:
```
$ make clean
```
> This command also clean hidden files, using rm -i .*

## Full Sequence Diagram of the Sim-SPR

<p align="center">
  <img src="https://user-images.githubusercontent.com/25873978/55831486-31228c80-5ae1-11e9-8c0c-e1b13339d84a.png">
</p>

## Sim-SPR Current Status and Future Improvements

- [x] Angular Interrogation Mode
- [x] Sensitivity Angular Interrogation Mode
- [x] Kretschmann and Otto configurations
- [X] Optical Fiber
- [x] Laser Light Source
- [x] N layers
- [ ] Wavelength Interrogation Mode
- [ ] Sensitivity Wavelength Interrogation Mode
- [ ] LED Light Source
- [ ] Anisotropy
- [ ] Graphical Interface

## Author

* **Elton Brasil da Costa** - [Curriculum Lattes (Portuguese)](http://buscatextual.cnpq.br/buscatextual/visualizacv.do?id=K4459901A6)
* Contact: elton.costa@ee.ufcg.edu.br

