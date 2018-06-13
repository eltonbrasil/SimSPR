clear;
clc;
%% Angular Interrogation Mode (AIM)
load au_670nm_AIM.txt
load ag_670nm_AIM.txt
load cu_670nm_AIM.txt
load bulk_AIM.txt
load bulk_830nm_AIM.txt

theta_au = au_670nm_AIM(:,1);
R_au = au_670nm_AIM(:,2);

theta_ag = ag_670nm_AIM(:,1);
R_ag = ag_670nm_AIM(:,2);

theta_cu = cu_670nm_AIM(:,1);
R_cu = cu_670nm_AIM(:,2);

theta_bulk = bulk_AIM(:,1);
R_AIM_bulk = bulk_AIM(:,2);

theta_bulk_830nm = bulk_830nm_AIM(:,1);
R_AIM_bulk_830nm = bulk_830nm_AIM(:,2);

%% Wavelength Interrogation Mode (WIM)
load au_670nm_WIM.txt
load ag_670nm_WIM.txt
load cu_670nm_WIM.txt
load bulk_WIM.txt
load bulk_830nm_WIM.txt

lambda_au = au_670nm_WIM(:,1);
R_WIM_au = au_670nm_WIM(:,2);

lambda_ag = ag_670nm_WIM(:,1);
R_WIM_ag = ag_670nm_WIM(:,2);

lambda_cu = cu_670nm_WIM(:,1);
R_WIM_cu = cu_670nm_WIM(:,2);

lambda_bulk = bulk_WIM(:,1);
R_WIM_bulk = bulk_WIM(:,2);

lambda_bulk_830nm = bulk_830nm_WIM(:,1);
R_WIM_bulk_830nm = bulk_830nm_WIM(:,2);

%% AIM waveform simulation
figure (1)
    plot (theta_au, R_au, 'linewidth', 3);

    xlabel('Angle of Incidence (degrees)', 'FontSize', 14)
    ylabel('Reflectivity', 'FontSize', 14)
    legend('Sim-SPR (Au)',14)

figure (2)
    plot (theta_ag, R_ag, 'linewidth', 3);

    xlabel('Angle of Incidence (degrees)', 'FontSize', 14)
    ylabel('Reflectivity', 'FontSize', 14)
    legend('Sim-SPR (Ag)',14)

figure (3)
    plot (theta_cu, R_cu, 'linewidth', 3);

    xlabel('Angle of Incidence (degrees)', 'FontSize', 14)
    ylabel('Reflectivity', 'FontSize', 14)
    legend('Sim-SPR (Cu)',14)

%% WIM waveform simulation
figure (4)
    plot (lambda_au, R_WIM_au, 'red', 'linewidth', 3);

    xlabel('Wavelenght (nm)', 'FontSize', 14)
    ylabel('Reflectivity', 'FontSize', 14)
    legend('Sim-SPR (Au)',14)
    
figure (5)
    plot (lambda_ag, R_WIM_ag, 'red', 'linewidth', 3);

    xlabel('Wavelenght (nm)', 'FontSize', 14)
    ylabel('Reflectivity', 'FontSize', 14)
    legend('Sim-SPR (Ag)',14)

figure (6)
    plot (lambda_cu, R_WIM_cu, 'red', 'linewidth', 3);

    xlabel('Wavelenght (nm)', 'FontSize', 14)
    ylabel('Reflectivity', 'FontSize', 14)
    legend('Sim-SPR (Cu)',14)
    
%% Bulk Sensing with four layers
figure (7)

    plot (theta_bulk, R_AIM_bulk, 'linewidth', 3);

    xlabel('Angle of Incidence (degrees)', 'FontSize', 14)
    ylabel('Reflectivity', 'FontSize', 14)
    legend('Sim-SPR (Bulk Sensing)',14)

figure (8)
    plot (lambda_bulk, R_WIM_bulk, 'red', 'linewidth', 3);

    xlabel('Wavelenght (nm)', 'FontSize', 14)
    ylabel('Reflectivity', 'FontSize', 14)
    legend('Sim-SPR (Bulk Sensing)',14)

figure (9)

    plot (theta_bulk_830nm, R_AIM_bulk_830nm, 'linewidth', 3);

    xlabel('Angle of Incidence (degrees)', 'FontSize', 14)
    ylabel('Reflectivity', 'FontSize', 14)
    legend('Sim-SPR (Bulk Sensing)',14)
    
figure (10)
    plot (lambda_bulk_830nm, R_WIM_bulk_830nm, 'red', 'linewidth', 3);

    xlabel('Wavelenght (nm)', 'FontSize', 14)
    ylabel('Reflectivity', 'FontSize', 14)
    legend('Sim-SPR (Bulk Sensing)',14)

