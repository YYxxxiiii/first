clear;
%程序参数的设定
Coord = ...%城市的坐标 Coordintes
[97.9849098	98.38094937	27.98931754	70.41640727	0.230983082	9.979678488	62.3661925	97.75242637	30.55018253	51.36937056	54.66377396	92.55792302	65.93941559	93.49355481	74.31910274	93.01654568	1.10793434	25.62558639	3.677285725	74.77258425	32.93394152	10.68354057	1.608918422	45.28425394	73.05274546	98.32549113	4.37486465	47.21796073	21.84028696	54.45224632	77.28516002	74.26693012	76.64474672	76.08788637	33.39112473	45.66459871	27.09648023	17.99980438	61.51512125	69.97869794	93.63278889	70.93183815	88.7270271	74.76901944	99.78485868	54.87597893	67.33292245	64.21088888	83.98574068	53.47879442	90.57162178	53.58845165	16.31014791	5.091263213	79.44341798	2.083833092	12.55053622	50.22457562	22.68455296	32.5320138	19.6441546	56.58630835	94.40001057	72.58193405	4.615823551	48.13102859	25.7498141	42.48943524	60.79661083	64.13153515	48.49736076	50.52871044	93.23445039	77.69496618	34.01707766	82.46380879	62.66583936	55.80008418	97.4462012	7.379237288	96.73874738	32.10125412	33.46924098	94.58036007	74.84888558	95.69666868	59.86799006	6.240329503	99.27011737	0.725557517	9.8236366	64.32233451	78.06640801	63.97240177	20.52674843	52.76280402	38.86206462	97.41068748	85.64858159	28.5838939	76.99971241	58.2118135	95.91029107	33.71642945	46.39446681	93.79175003	45.78386109	13.97031836	91.00620565	83.58110811	6.708442924	98.48674643	66.11728435	81.29863152	26.35711557	42.49769339	43.20796774	12.6509286	19.28997304	17.42214664	80.64950087	74.69161672	56.38732952	42.28552089	55.16191084	67.14034262	99.06995875	34.31099318	36.72107607	16.73797803	22.53899784	54.03796849	95.46576766	69.27047356	25.15850311	7.106993294	84.91841071	28.45941333	69.10989193	31.87930166	61.08878265	84.1968388	2.916090882	59.60799775	9.872094425	66.12118468	15.17695793	1.234210595	86.91052552	25.49244131	27.33653798	68.96423808	24.01575915	80.06943396	25.48705037	40.88090881	96.25387344	86.73835544	59.97647629	62.388202	36.88439701	40.11801367	16.77155934	46.86161957	18.54645749	66.30147134	91.8140663	15.23914327	82.33008772	43.69769521	32.39524177	33.10659276	22.96670559	89.72128847	52.68979874	89.8259944	2.917170861	11.07747494	87.68211807	76.07224245	67.43480694	4.524448982	25.67330722	21.42611385	42.70798288	89.17946645	97.94224183	36.8266224	61.5102675	90.08031879	25.85726471	74.95412706	39.1519508	95.77571697	68.94582611	57.34104826	69.39839075	90.31107454	96.02858995	14.59991433;...
84.00603423	3.816468942	16.05115379	58.4756742	48.96762198	1.552363529	96.74564172	39.86505766	65.13316425	72.41088838	88.13790612	68.40477675	49.58028178	60.59233114	52.70699288	1.628130347	90.05347513	94.82808338	51.27924162	35.40772473	15.63667991	81.66108583	12.97574813	76.1531538	20.06517373	16.53362115	37.19708696	22.9083133	32.02374048	35.04613268	76.81249886	14.12321188	12.65849009	96.65340599	47.98688861	65.56004528	55.69106069	63.18047121	96.54002926	80.19107608	50.60634915	68.68239444	40.77692541	34.59125867	62.89245419	49.8835059	27.84546036	78.5023025	42.12350112	80.76507379	8.716421869	77.00633541	12.41921597	43.74214772	40.43257075	72.10156901	68.20199174	53.97961934	34.61492084	15.93328176	41.24161028	55.27366145	64.89651208	4.581296272	83.04108785	36.55531301	2.190530484	37.60523288	59.64069243	54.98268744	22.53780058	28.78204087	58.83734536	30.44069693	64.28573044	43.07142465	73.45955516	60.22134223	76.32843717	86.62863341	90.19526837	85.81988559	85.00618482	23.20381102	34.97002417	55.357567	41.21835041	35.78271204	83.08978174	89.70001752	63.11583151	14.60920953	10.52743747	87.84564471	15.13235255	17.25147523	46.58344328	64.46830342	6.195872766	42.64505314	46.37463768	29.33907661	51.69423386	26.11195744	83.07055702	63.43850674	81.35532802	13.23155253	15.0807119	80.3256885	40.93824487	50.63557743	55.50066044	52.30982287	29.07763995	46.15822771	89.38814325	55.11140133	62.94608113	99.24608617	30.98864211	42.32067455	13.79016468	36.62264318	55.41485609	19.54641911	9.094040068	28.14025257	92.87280831	19.36002246	45.70381141	13.67530675	35.33281441	26.61559698	76.22726614	16.49077491	19.38765952	81.42842404	75.22245471	69.95991949	11.56034162	75.34970301	19.14771559	29.85486503	18.23773446	30.80045611	3.56292803	87.9354735	52.4669544	88.30564352	58.33631608	64.25791773	91.21807948	59.35299809	20.91911566	95.27781315	22.84775045	6.59229485	78.79744785	55.61475355	33.51251486	58.264168	65.46181677	19.16856792	15.23349816	38.1408457	2.409723322	92.02461797	73.86602855	38.32347519	17.43634375	53.09201275	19.35247194	1.425933612	87.22545288	80.56191638	26.73616994	69.71862547	65.38014188	69.95385219	45.4148753	33.54222367	46.6872333	59.87072138	25.01959387	73.71895617	48.32078357	91.440244	52.55385238	15.16612417	3.857888032	42.58549032	2.290260063	37.51826975	55.8025874	91.28199977	13.59100968	50.20675199	94.82142446	33.63180115];
t0=1,%初始温度t0
iLk = 20000; %内循环最大迭代次数iLk
oLk = 50000; %外循环最大迭代次数oLk
lam = 0.95  % lambda
istd =0.00000001;%若内循环函数值方差小于istd则停止
ostd =0.00000001;%若外循环函数值方差小于ostd则停止
ilen = 200; %内循环保存的目标函数值的个数
olen = 200; %外循环保存的目标函数值的个数
%程序主体
m=length(Coord);%城市的个数m
fare = distance(Coord);     %路径费用 
path=1:m;
pathfar=pathfare(fare,path);
ores=zeros(1,olen);
e0=pathfar;%能量初值为e0
t=t0;
for out=1:oLk%外循环模拟退火过程
ires =zeros(1,ilen);
for in=1:iLk%内循环模拟热平衡过程
[newpath,v]=swap(path,1);
 e1=pathfare(fare,newpath);%新状态能量
  %Metropolis抽样稳定准则
   r=min(1,exp(-(e1-e0)/t));
  if rand< r
      path=newpath;%更新最新状态
          e0=e1;
  end
  ires=[ires(2:end) e0];
  if std(ires ,1)<istd
break;
end
end
 ores=[ores(2:end) e0];
 if std(ores ,1)<ostd
 break
 end
 t=lam*t;
end
pathfar= e0;
%输出结果
fprintf('近似最优路径为：\n')
%disp(char([path,path(1)  ] +64))
disp(path)
fprintf('近似最优路径为：\tapthfare=');
disp(pathfar);
myplot(path,Coord,pathfar);       