clf

figure(1)
for i = 1:3
    subplot(3,1,i)
    plot(Avant.time,Avant.signals.values(:,i))
end

figure(2)
for i = 1:3
    subplot(3,1,i)
    plot(Apres.time,Apres.signals.values(:,i))
end

figure(3)
for i = 1:3
    subplot(3,1,i)
    plot(Difference.time,Difference.signals.values(:,i))
end

figure(4)
plot(Move.time,Move.signals.values)