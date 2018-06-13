clear;
clc;
%% Angular Interrogation Mode (AIM)
load au_670nm_AIM.txt
load ag_670nm_AIM.txt
load cu_670nm_AIM.txt

theta_au = au_670nm_AIM(:,1);
R_au = au_670nm_AIM(:,2);

theta_ag = ag_670nm_AIM(:,1);
R_ag = ag_670nm_AIM(:,2);

theta_cu = cu_670nm_AIM(:,1);
R_cu = cu_670nm_AIM(:,2);

%% AIM waveform simulation
figure (1)
    L1 = plot (theta_au, R_au, 'MarkerSize', 20, 'linewidth', 5);
    hold on
    L2 = plot (theta_au, R_au, '--r', 'MarkerSize', 20, 'linewidth', 5);
    hold off
    
    grid on
    grid minor
    axis([20 50 0 1]) % Ajuste fino
    xlabel('Ângulo de Incidência (graus)', 'FontSize', 20)
    ylabel('Reflectância', 'FontSize', 20)
    set(gca,'FontSize',25)
    legend('Sim-SPR (Au)', 'COMSOL (Au)','FontSize', 20)
         
figure (2)
    plot (theta_ag, R_ag, 'linewidth', 5);
    hold on
    plot (theta_ag, R_ag, '--r', 'linewidth', 5);
    hold off
    grid on
    axis([20 50 0 1]) % Ajuste fino
    xlabel('Ângulo de Incidência (graus)', 'FontSize', 20)
    ylabel('Reflectância', 'FontSize', 20)
    set(gca,'FontSize',25)
    legend('Sim-SPR (Ag)', 'COMSOL (Ag)','FontSize', 20)

figure (3)
    plot (theta_cu, R_cu, 'linewidth', 5);
    hold on
    plot (theta_cu, R_cu, '--r', 'linewidth', 5);
    hold off
    grid on
    axis([20 50 0 1]) % Ajuste fino
    xlabel('Ângulo de Incidência (graus)', 'FontSize', 20)
    ylabel('Reflectância', 'FontSize', 20)
    set(gca,'FontSize',25)
    legend('Sim-SPR (Cu)', 'COMSOL (Cu)','FontSize', 20)
