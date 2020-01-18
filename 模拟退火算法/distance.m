function[fare]=distance(coord) %根据各城市的距离坐标求相互之间的距离 
%fare为各城市之间的距离，coord为各城市的坐标
[v,m]=size(coord); %m为城市的个数
fare=zeros(m);
for i =1:m %外层为行
for j =1:m %内层为列
fare(i,j)=(sum((coord(:,i)-coord(:,j)).^2))^0.5;
fare(j,i)=fare(i,j);% 距离矩阵对称
end 
end