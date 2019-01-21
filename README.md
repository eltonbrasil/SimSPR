![logo](https://user-images.githubusercontent.com/25873978/47947397-7c18f200-defa-11e8-9943-9d10470bd2b9.png)

# An Open-Source Simulator for Surface Plasmon Resonance Applications
## Description:

We present our free, open-source simulator for Surface Plasmon Resonance (SPR) applications implemented in C++ language.

## Characteristics:

* Number of Layers: N layers;
* Configuration: Otto (a) and Kretschmann (b);
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

## Download Sim-SPR:
```
$ git clone https://github.com/eltonbrasil/SimSPR.git 
```

## Running tests

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
$ make all
```
### To run your simulation:
```
$ make run
```
### After to run your simulation, you will be presented to the "Welcome to Sim-SPR", in which you can choose the SPR sensor configuration, presented as:

<p align="center">
  <img src="https://user-images.githubusercontent.com/25873978/51501474-2ba68780-1db9-11e9-8b65-65ef8cb1c15e.png">
</p>

### Also, you can configure the start incidence angle (line 16) in radians as well as the step-scale (line 20), both in the testbench file

<p align="center">
  <img src="https://user-images.githubusercontent.com/25873978/51501765-6361ff00-1dba-11e9-8eda-c3542fa904ed.png">
</p>

### To clean unnecessary files:
```
$ make clean
```
### To plot waveforms:
```
$ gnuplot
$ load 'out.gnu'
```

## Author

* **Elton Brasil da Costa** - [Curriculum Lattes (Portuguese)](http://buscatextual.cnpq.br/buscatextual/visualizacv.do?id=K4459901A6)
* Contact: elton.costa@ee.ufcg.edu.br

