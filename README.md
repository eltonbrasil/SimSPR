![logo](https://user-images.githubusercontent.com/25873978/47947397-7c18f200-defa-11e8-9943-9d10470bd2b9.png)

# An Open-Source Simulator for Surface Plasmon Resonance Applications
## Description:

We present our free, open-source simulator for Surface Plasmon Resonance (SPR) applications implemented in C++ language. 

## Characteristics:

* Number of Layers: N layers
* Configuration: Kretschmann and Otto
* License: Open Source
* Language: C++
* Operation: Angular Interrogation Mode (AIM)

## Prerequisites:

* G++ Compile (C++11 version)
* Linux Terminal to compile Sim-SPR
* GNUplot to plot waveforms

## Running tests

You can compile Sim-SPR using Makefile technique, given by following commands: 
### Testbench folder
```
$ cd testbench
```
### Help
```
$ make help
```
### To compile your testbench using G++ tools
```
$ make test
```
### To run your simulation
```
$ make run
```
### To clean unnecessary files
```
$ make clean
```
### To plot waveforms
```
$ gnuplot
$ load 'out.gnu'
```

## Author

* **Elton Brasil da Costa** - [Curriculum Lattes (Portuguese)](http://buscatextual.cnpq.br/buscatextual/visualizacv.do?id=K4459901A6)
* Contact: elton.costa@ee.ufcg.edu.br
