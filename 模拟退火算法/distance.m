function[fare]=distance(coord) %���ݸ����еľ����������໥֮��ľ��� 
%fareΪ������֮��ľ��룬coordΪ�����е�����
[v,m]=size(coord); %mΪ���еĸ���
fare=zeros(m);
for i =1:m %���Ϊ��
for j =1:m %�ڲ�Ϊ��
fare(i,j)=(sum((coord(:,i)-coord(:,j)).^2))^0.5;
fare(j,i)=fare(i,j);% �������Գ�
end 
end