import streamlit as st
import pandas as pd # Para la manipulación y análisis de los datos
import numpy as np                # Para crear vectores y matrices n dimensionales
from  matplotlib import pyplot as plt  # Para la generación de gráficas a partir de los datos
from streamlit.cli import main
import seaborn as sns
############################
from sklearn.decomposition import PCA
from sklearn.preprocessing import StandardScaler, MinMaxScaler 
##############################
from apyori import apriori
##############################
from sklearn.preprocessing import StandardScaler, MinMaxScaler 
#Se importan las bibliotecas de clustering jerárquico para crear el árbol
import scipy.cluster.hierarchy as shc
from sklearn.cluster import AgglomerativeClustering
#Se importan las bibliotecas
from sklearn.cluster import KMeans
from sklearn.metrics import pairwise_distances_argmin_min
from kneed import KneeLocator
#Se importan las bibliotecas necesarias para generar los modelos
from sklearn import model_selection
from sklearn.metrics import classification_report
from sklearn.metrics import confusion_matrix
from sklearn.metrics import accuracy_score
from sklearn.metrics import max_error
###Regresión lineal multiple
from sklearn import linear_model
###Arbol de Decision
from sklearn.tree import DecisionTreeRegressor
from sklearn.metrics import mean_squared_error, mean_absolute_error, r2_score
from sklearn import model_selection
###Bosque Aleatorio
from sklearn.ensemble import RandomForestRegressor
###Arbol de Decision Claisficacion
from sklearn.tree import DecisionTreeClassifier
###Bosque Aleatorio Clasificacion
from sklearn.ensemble import RandomForestClassifier

#from streamlit_pandas_profiling import st_profile_report

#titulo de la GUI

st.set_page_config(
    page_title="PanicAtomic", page_icon="📊", initial_sidebar_state="expanded"
)

st.markdown('''
# 📊 **PanicAtomic**

Esta es una GUI creada con `Streamlit`

**Credit:** Puente López Gandhi Yael

---
	''')

#subir datos
st.set_option('deprecation.showPyplotGlobalUse', False)

with st.sidebar.header('1. Carga tus datos CSV'):
	uploaded_file = st.sidebar.file_uploader("Carga tu archivo")
	dataNoHeader = st.sidebar.button("Data no Header")

st.sidebar.header('2. Selecciona un metodo o proceso de minería de datos')

with st.sidebar.header('2.1 Análisis Exploratorio de Datos'):
	EDA = st.sidebar.button("EDA")
	my_form = st.sidebar.form(key="form1")
	header = my_form.number_input("Mostrar los primeros", min_value=1,max_value=50,step=1)
	enter_h = my_form.form_submit_button(label = "Enter")

	###
st.sidebar.header('2.2 Componente: Selección de características:')
with st.sidebar.header('2.2.1 Análisis de Componentes Principales (ACP)'):
	ACP = st.sidebar.button("ACP")

with st.sidebar.header('2.2.1 Análisis de Correlacional de los Datos (ACD)'):
	ACD = st.sidebar.button("ACD")
	my_form2 = st.sidebar.form(key="form2")
	header2 = my_form2.text_input("Evaluación visual")
	enter_h2 = my_form2.form_submit_button(label = "Enter")
	my_form3 = st.sidebar.form(key="form3")
	header3 = my_form3.text_input("Top 10 valores de correlación")
	enter_h3 = my_form3.form_submit_button(label = "Enter")
	
with st.sidebar.header('2.3 Clustering Jerárquico'):
	ClusteringJ = st.sidebar.button("Clustering Jerarquico")
	my_form_CJ = st.sidebar.form(key="formCJ")
	number_CJ= my_form_CJ.number_input("Número de clusters",min_value=2)
	enter_CJ = my_form_CJ.form_submit_button(label = "Enter")
	my_form_CN = st.sidebar.form(key="formCN")
	cluster_n= my_form_CN.number_input("Qué cluster quieres mostrar",min_value=0)
	enter_NC = my_form_CN.form_submit_button(label = "Enter")
	Centroides=st.sidebar.button("Centroides Clustering Jerárquico")
with st.sidebar.header('2.4 Clustering Particional'):
	ClusteringP = st.sidebar.button("Clustering Particional")
	my_form_CP = st.sidebar.form(key="formCP")
	cluster_n_2= my_form_CP.number_input("Qué cluster quieres mostrar",min_value=0)
	enter_NC_2 = my_form_CP.form_submit_button(label = "Enter")
	Centroides_2=st.sidebar.button("Centroides Clustering Particional")

with st.sidebar.header('2.5 Reglas de Asosiación Algoritmo Apriori'):	
	Apriori = st.sidebar.button("Apriori")
	my_form5 = st.sidebar.form(key="form5")
	support = my_form5.number_input("Support",min_value=0.01)
	confidence = my_form5.number_input("Confidence",min_value=0.1)
	litf = my_form5.number_input("Lift",min_value=1.01)
	enter_hA = my_form5.form_submit_button(label = "Enter")
	impReglas = st.sidebar.button("Impresión de reglas")
	my_form6 = st.sidebar.form(key="form6")
	reglaEx= my_form6.number_input("Ver regla exacta",min_value=1)
	enterRegla = my_form6.form_submit_button(label = "Enter")

with st.sidebar.header('2.6 Pronostico: Fuerza del Concreto'):
	st.sidebar.header('2.6.1 Pronóstico (Árbol de decisión) y (Bosques Aleatorios)')
	ResultadosAB= st.sidebar.button("Resultados (Pronóstico) de Árbol de decisión y Bosques Aleatorios")
	my_form_AP = st.sidebar.form(key="formAP")
	Cement = my_form_AP.number_input("Cement",min_value=1)
	Blast_Furnace_Slag = my_form_AP.number_input("Blast Furnace Slag",min_value=1)
	Fly_Ash = my_form_AP.number_input("Fly Ash",min_value=0.0)
	Water = my_form_AP.number_input("Water",min_value=1)
	Superplasticizer = my_form_AP.number_input("Superplasticizer",min_value=1)
	Coarse_Aggregate = my_form_AP.number_input("Coarse Aggregate",min_value=1)
	Fine_Aggregate = my_form_AP.number_input("Fine Aggregate",min_value=1)
	Age = my_form_AP.number_input("Age",min_value=1)
	enterDatosAB = my_form_AP.form_submit_button(label = "Enter")

with st.sidebar.header('2.7 Clasificación: Cadena de distribucion de Whosale'):
	st.sidebar.header('2.7.1 Clasificación (Árbol de decisión) y (Bosques Aleatorios)')
	ResultadosAB_2= st.sidebar.button("Resultados (Clasificación) de Árbol de decisión y Bosques Aleatorios")
	my_form_AB = st.sidebar.form(key="formAB")
	Region = my_form_AB.number_input("Region",min_value=1)
	Fresh= my_form_AB.number_input("Fresh",min_value=1)
	Milk = my_form_AB.number_input("Milk",min_value=1)
	Grocery = my_form_AB.number_input("Grocery",min_value=1)
	Frozen = my_form_AB.number_input("Frozen",min_value=1)
	Detergents_Paper = my_form_AB.number_input("Detergents_Paper",min_value=1)
	Delicassen = my_form_AB.number_input("Delicassen",min_value=1)
	enterDatosAB_2 = my_form_AB.form_submit_button(label = "Enter")

	
if uploaded_file is not None:
	@st.cache
	def load_csv():
		csv = pd.read_csv(uploaded_file)
		return csv
	def load_csv_nh():
		csv_nh = pd.read_csv(uploaded_file, header=None)
		return csv_nh
	def convert_df(file):
   		return file.to_csv().encode('utf-8')
	df = load_csv()
	df_nh = load_csv_nh()
	#pr = ProfileReport(df, explorative=True)
	st.header("**Input DataFrame**")
	st.write(df)

	st.header("**Diagrama de cajas**")
	st.write("**Los diagramas de cajas sirven para detectar valores atípicos o volres que se alejan demaciado del rango común.**")
	try:
		columnas=list(df)
		result = st.selectbox("Selecciona un item",columnas)
		sns.boxplot(result, data=df)
		st.pyplot()
	except:
		st.write("**Varible no apta para diagrama de cajas**")

	st.header("**Selección de variables**")
	columnasV=list(df)
	options=st.multiselect("Variables a eliminar",columnasV)
	st.write(options)
	st.write("**Nueva matriz de información**")
	DatosEliminados = df.drop(columns=options)
	st.write(DatosEliminados)
	csv_d= convert_df(DatosEliminados)
	st.download_button("Press to Download",csv_d,"file.csv","text/csv",key='download-csv')

	if dataNoHeader:
		st.header("**Input DataFrame No Header**")
		st.write(df_nh)
	if EDA:
	#st.header("**Pandas Profile Report**")
		###################################
		st.title("**1. Descripción de la estructura de los datos**")
		st.header("**Input 10 Data Head**")
		st.write("Es importante mostrar cierta cantidad de datos para visulizar la data.")
		st.write(df.head(10))
		st.header("**Data types**")
		st.write("El siguiente despligue muestra los tipos de datos de las columnas (variables y tipos).")
		types=str(df.dtypes)
		st.text(types)
		st.header("**Filas y columnas**")
		st.write("Devolvemos la cantidad de filas y columnas que tiene el conjunto de datos.")
		shape=str(df.shape)
		st.text(shape)
		###################################
		st.title("**2. Identificación de datos faltantes**")
		st.header("**Suma de datos faltantes**")
		st.write("Observamos el total de datos faltantes de cada variable.")
		sum_datos=df.isnull().sum()
		st.text(sum_datos)
		###################################
		st.title("**3. Detección de valores atípicos**")
		st.header("**Histograma**")
		text_histo="""Un histograma es una representación gráfica de una variable en forma de barras, 
					teniendo en cuenta que la superficie de cada barra es proporcional a la frecuencia de los valores representados. 
					Un histograma nos permite ver cómo se distribuyen los valores de la variable en estudio."""
		st.write(text_histo)
		df.hist(figsize=(14,14), xrot=45)
		st.pyplot()
		st.header("**Descripción de los datos**")
		st.write("A continuación se muestra un resumen estadístico de las variables numéricas.")
		descrip=df.describe()
		st.write(descrip)
		st.title("**Identificación de relaciones entre pares variables**")
		st.header("**Correlación**")
		text_corr="""La correlación es una medida estadística que expresa hasta qué punto dos variables están relacionadas linealmente (esto es, cambian conjuntamente a una tasa constante). 
					Es una herramienta común para describir relaciones simples sin hacer afirmaciones sobre causa y efecto."""
		st.write(text_corr)
		correlacion = df.corr()
		st.write(correlacion)
		st.header("**Plot Correlación**")
		plt.figure(figsize=(14,7))
		MatrizInf = np.triu(df.corr())
		sns.heatmap(df.corr(), cmap='RdBu_r', annot=True, mask=MatrizInf)
		st.pyplot()
		st.write("**- Una correlación es un valor entre -1 y 1 que equivale a qué tan cerca se mueven simultáneamente los valores de dos variables.**")
		st.write("**- Una correlación positiva significa que a medida que una característica aumenta, la otra también aumenta.**")
		st.write("**- Una correlación negativa significa que a medida que una característica disminuye, la otra también disminuye.**")
		st.write("**- Las correlaciones cercanas a 0 indican una relación débil, mientras que las más cercanas a -1 o 1 significan una relación fuerte.**")
	###################################
	if enter_h:
		st.header("**Input 'N' Data Head**")
		st.write("Despliegue de n cantidad de valores de la data")
		st.write(df.head(header))

##############################################ACP
	if ACP:

		st.title("**Análisis de componentes principales (ACP)**")
		st.write("**1. Se hace una estandarización de los datos**")
		st.write("**2. Se calcula la matriz de covarianzas o correlaciones.**")
		st.write("**3. Se calculan los componentes (eigen-vectores) y la varianza (eigen-valores).**")
		st.write("**4. Se decide el número de componentes principales.**")
		st.write("**5. Se examina la proporción de relevancias –cargas–**")
		Estandarizar = StandardScaler()               	 # Se instancia el objeto StandardScaler o MinMaxScaler 
		MEstandarizada = Estandarizar.fit_transform(df)  # Se calculan la media y desviación para cada variable, y se escalan los datos
		st.title("**Estandarización de los datos**")
		st.header("**Datos Estandarizados**")
		df_estandar = pd.DataFrame(MEstandarizada, columns=df.columns)
		st.write(df_estandar)
		##############################################
		st.header("**Matriz de covarianzas o correlaciones, componentes (eigen-vectores) y la varianza (eigen-valores)**")
		pca = PCA(n_components=10)          # Se instancia el objeto PCA    #pca=PCA(n_components=None), pca=PCA(.85)
		pca.fit(MEstandarizada)             # Se obtiene los componentes
		st.text(pca.components_)
		##############################################
		st.header("**Número de componentes principales**")
		Varianza = pca.explained_variance_ratio_
		st.write('Porporción de varianza:', Varianza)
		st.write('Varianza acumulada:', sum(Varianza[0:6]))  
		st.header("**Se grafica la varianza acumulada en los componentes**") #Se grafica la varianza acumulada en los componentes
		plt.plot(np.cumsum(pca.explained_variance_ratio_))
		plt.xlabel('Número de componentes')
		plt.ylabel('Varianza acumulada')
		plt.grid()
		st.pyplot() 
		st.header("**Se examina la proporción de relevancias –cargas–**") 
		st.write(pd.DataFrame(abs(pca.components_)))
		st.markdown("**Cargas con nombre y valor `absoluto`**")
		CargasComponentes = pd.DataFrame(abs(pca.components_), columns=df.columns)
		st.write(CargasComponentes) 
		
####################################ACD
	if ACD:
		st.title("**Análisis correlacional de datos**")
		st.header("**Matriz correlacional por el metodo de: `Pearson`**")
		CorrDF = df.corr(method='pearson')
		st.write(CorrDF)
		st.header("**Matriz correlacional**")
		plt.figure(figsize=(14,7))
		MatrizInf = np.triu(CorrDF)
		sns.heatmap(CorrDF, cmap='RdBu_r', annot=True, mask=MatrizInf)
		st.pyplot()
		st.write("**- Una correlación es un valor entre -1 y 1 que equivale a qué tan cerca se mueven simultáneamente los valores de dos variables.**")
		st.write("**- Una correlación positiva significa que a medida que una característica aumenta, la otra también aumenta.**")
		st.write("**- Una correlación negativa significa que a medida que una característica disminuye, la otra también disminuye.**")
		st.write("**- Las correlaciones cercanas a 0 indican una relación débil, mientras que las más cercanas a -1 o 1 significan una relación fuerte.**")
	if enter_h2:
		st.title("**Análisis correlacional de datos**")
		st.header("**Evaluación visual**")
		st.header("`Espere un momento...`**")
		sns.pairplot(df, hue=header2)
		st.pyplot()
	if enter_h3:
		st.title("**Análisis correlacional de datos**")
		st.header("**Matriz correlacional por el metodo de: `Pearson`**")
		CorrDF = df.corr(method='pearson')
		st.write(CorrDF)
		st.header("**Top 10 valores de correlación**")
		CorrDF = df.corr(method='pearson')
		Top10=CorrDF[header3].sort_values(ascending=False)[:10]   #Top 10 valores
		st.write(Top10) 

##########################Clustering jerarquico
	if ClusteringJ:
		st.title("**Clustering Jerarquico**")
		st.header("**Notas:**")
		st.write("**- Para la aplicaión de este algoritmo debes utilizar una data donde ya hayas seleccionado las varibles más importantes o relevantes**")
		st.write("**- Si aún no has hecho el punto anterior dirígete a la sección de Selección de Variables para modificar tu data y descargar una nueva versión.**")
		st.header("**Nueva matriz sin nombres de columnas**")
		st.write("Los valores se acomodan de cierta forma para que el algoritmo trabaje con los datos.")
		Matriz = np.array(df)
		Matriz_NoName=pd.DataFrame(Matriz)
		st.write(Matriz_NoName)
		st.title("**Aplicación del algoritmo: Jerárquico Ascendente**")
		st.header("**Estandarización de los datos**")
		st.write("Cuando se trabaja con clustering, dado que son algoritmos basados en distancias, es fundamental escalar los datos para que cada una de las variables contribuyan por igual en el análisis.")
		estandarizar = StandardScaler()                               # Se instancia el objeto StandardScaler o MinMaxScaler 
		MEstandarizada = estandarizar.fit_transform(Matriz)   # Se calculan la media y desviación y se escalan los datos
		Data_Estandar= pd.DataFrame(MEstandarizada) 
		st.write(Data_Estandar)
		st.header("**Arbol de clustering**")
		st.write("Este arbool sirve para observar la cantidad de clústers que hay en nuestra data, el problema es que se tiene que seleccionar de forma manual")
		plt.figure(figsize=(10, 7))
		plt.title("Casos")
		plt.xlabel('Datos de estudio')
		plt.ylabel('Distancia')
		Arbol = shc.dendrogram(shc.linkage(MEstandarizada, method='complete', metric='euclidean'))
		st.pyplot() 
		st.header("**Después de observar el arbol selecciona el número de clusters en la barra lateral**")
	if enter_CJ:
		st.title("**Aplicación del algoritmo: Jerárquico Ascendente**")
		Matriz = np.array(df)
		estandarizar = StandardScaler()                               # Se instancia el objeto StandardScaler o MinMaxScaler 
		MEstandarizada = estandarizar.fit_transform(Matriz)   # Se calculan la media y desviación y se escalan los datos
		Data_Estandar= pd.DataFrame(MEstandarizada) 
		st.header("**Etiquetas de los elementos en los clústeres**")
		#Se crean las etiquetas de los elementos en los clústeres
		MJerarquico = AgglomerativeClustering(n_clusters=number_CJ, linkage='complete', affinity='euclidean')
		MJerarquico.fit_predict(MEstandarizada)
		st.write(MJerarquico.labels_)
		df['clusterH'] = MJerarquico.labels_
		nuevo_df=df
		st.header("**Nuevos datos con la columna clusters añadida**")
		st.write(nuevo_df)
		st.header("**Numero de elementos por cluster**")
		#Cantidad de elementos en los clusters
		st.write(nuevo_df.groupby(['clusterH'])['clusterH'].count())

	if enter_NC:
		st.title("**Aplicación del algoritmo: Jerárquico Ascendente**")
		st.header("**Cluster número**")
		st.header(cluster_n)
		st.header("**Elementos**")
		Matriz = np.array(df)
		estandarizar = StandardScaler()                               # Se instancia el objeto StandardScaler o MinMaxScaler 
		MEstandarizada = estandarizar.fit_transform(Matriz)   # Se calculan la media y desviación y se escalan los datos
		Data_Estandar= pd.DataFrame(MEstandarizada)
		#Se crean las etiquetas de los elementos en los clústeres
		MJerarquico = AgglomerativeClustering(n_clusters=number_CJ, linkage='complete', affinity='euclidean')
		MJerarquico.fit_predict(MEstandarizada)
		df['clusterH'] = MJerarquico.labels_
		nuevo_df=df
		#Cantidad de elementos en los clusters
		nuevo_df.groupby(['clusterH'])['clusterH'].count()
		nuevo_df[nuevo_df.clusterH == cluster_n]
	if Centroides:
		st.title("**Aplicación del algoritmo: Jerárquico Ascendente**")
		st.header("**Centroides finales para el análisis**")
		Matriz = np.array(df)
		estandarizar = StandardScaler()                               # Se instancia el objeto StandardScaler o MinMaxScaler 
		MEstandarizada = estandarizar.fit_transform(Matriz)   # Se calculan la media y desviación y se escalan los datos
		Data_Estandar= pd.DataFrame(MEstandarizada)
		#Se crean las etiquetas de los elementos en los clústeres
		MJerarquico = AgglomerativeClustering(n_clusters=number_CJ, linkage='complete', affinity='euclidean')
		MJerarquico.fit_predict(MEstandarizada)
		df['clusterH'] = MJerarquico.labels_
		nuevo_df=df
		CentroidesH = nuevo_df.groupby('clusterH').mean()
		st.write(CentroidesH)
#################################
	if ClusteringP:
		st.title("**Clustering Particional**")
		st.header("**Notas:**")
		st.write("**- Para la aplicaión de este algoritmo debes utilizar una data donde ya hayas seleccionado las varibles más importantes o relevantes**")
		st.write("**- Si aún no has hecho el punto anterior dirígete a la sección de Selección de Variables para modificar tu data y descargar una nueva versión.**")
		st.header("**Nueva matriz sin nombres de columnas**")
		st.write("Los valores se acomodan de cierta forma para que el algoritmo trabaje con los datos.")
		Matriz = np.array(df)
		Matriz_NoName=pd.DataFrame(Matriz)
		st.write(Matriz_NoName)
		st.title("**Aplicación del algoritmo: K-Means**")
		st.header("**Estandarización de los datos**")
		st.write("Cuando se trabaja con clustering, dado que son algoritmos basados en distancias, es fundamental escalar los datos para que cada una de las variables contribuyan por igual en el análisis.")
		estandarizar = StandardScaler()                               # Se instancia el objeto StandardScaler o MinMaxScaler 
		MEstandarizada = estandarizar.fit_transform(Matriz)   # Se calculan la media y desviación y se escalan los datos
		Data_Estandar= pd.DataFrame(MEstandarizada) 
		st.write(Data_Estandar)
		st.header("**Definición de k clusters para K-means**")
		#Se utiliza random_state para inicializar el generador interno de números aleatorios
		SSE = []
		for i in range(2, 12):
			km = KMeans(n_clusters=i, random_state=0)
			km.fit(MEstandarizada)
			SSE.append(km.inertia_)
		plt.figure(figsize=(10, 7))
		plt.plot(range(2, 12), SSE, marker='o')
		plt.xlabel('Cantidad de clusters *k*')
		plt.ylabel('SSE')
		plt.title('Elbow Method')
		st.pyplot() 
		kl = KneeLocator(range(2, 12), SSE, curve="convex", direction="decreasing")
		st.header(kl.elbow)
		st.header("**Grafica con marca**")
		plt.style.use('ggplot')
		kl.plot_knee()
		st.pyplot()
		st.header("**Etiquetas de los elementos en los clústeres**")
		#Se crean las etiquetas de los elementos en los clusters
		MParticional = KMeans(n_clusters=kl.elbow, random_state=0).fit(MEstandarizada)
		MParticional.predict(MEstandarizada)
		MParticional.labels_
	if enter_NC_2:
		st.title("**Aplicación del algoritmo: K-Means**")
		st.header("**Cluster número**")
		st.header(cluster_n_2)
		Matriz = np.array(df)
		Matriz_NoName=pd.DataFrame(Matriz)
		estandarizar = StandardScaler()                               # Se instancia el objeto StandardScaler o MinMaxScaler 
		MEstandarizada = estandarizar.fit_transform(Matriz)   # Se calculan la media y desviación y se escalan los datos
		Data_Estandar= pd.DataFrame(MEstandarizada)
		SSE = []
		for i in range(2, 12):
			km = KMeans(n_clusters=i, random_state=0)
			km.fit(MEstandarizada)
			SSE.append(km.inertia_)
		kl = KneeLocator(range(2, 12), SSE, curve="convex", direction="decreasing")
		MParticional = KMeans(n_clusters=kl.elbow, random_state=0).fit(MEstandarizada)
		MParticional.predict(MEstandarizada)
		MParticional.labels_
		nuevo_df=df
		nuevo_df['clusterP'] = MParticional.labels_
		#Cantidad de elementos en los clusters
		st.header("**Número de elementos por clúster**")
		st.write(nuevo_df.groupby(['clusterP'])['clusterP'].count())
		st.header("**Elementos**")
		nuevo_df[nuevo_df.clusterP == cluster_n_2]
	if Centroides_2:
		st.title("**Aplicación del algoritmo: K-Means**")
		Matriz = np.array(df)
		Matriz_NoName=pd.DataFrame(Matriz)
		estandarizar = StandardScaler()                               # Se instancia el objeto StandardScaler o MinMaxScaler 
		MEstandarizada = estandarizar.fit_transform(Matriz)   # Se calculan la media y desviación y se escalan los datos
		Data_Estandar= pd.DataFrame(MEstandarizada)
		SSE = []
		for i in range(2, 12):
			km = KMeans(n_clusters=i, random_state=0)
			km.fit(MEstandarizada)
			SSE.append(km.inertia_)
		kl = KneeLocator(range(2, 12), SSE, curve="convex", direction="decreasing")
		MParticional = KMeans(n_clusters=kl.elbow, random_state=0).fit(MEstandarizada)
		MParticional.predict(MEstandarizada)
		MParticional.labels_
		nuevo_df=df
		nuevo_df['clusterP'] = MParticional.labels_
		#Cantidad de elementos en los clusters
		st.header("**Número de elementos por clúster**")
		st.write(nuevo_df.groupby(['clusterP'])['clusterP'].count())
		st.header("**Centroides finales para el análisis**")
		CentroidesP = nuevo_df.groupby('clusterP').mean()
		st.write(CentroidesP)
##########################Apriori
	if Apriori:
		st.title("**Reglas de Asosiación**")
		st.header("**Algoritmo: `Apriori`**")
		#Se incluyen todas las transacciones en una sola lista
		Transacciones = df_nh.values.reshape(-1).tolist() #-1 significa 'dimensión no conocida'
		#Se crea una matriz (dataframe) usando la lista y se incluye una columna 'Frecuencia'
		ListaM = pd.DataFrame(Transacciones)
		ListaM['Frecuencia'] = 0
		#Se agrupa los elementos
		ListaM = ListaM.groupby(by=[0], as_index=False).count().sort_values(by=['Frecuencia'], ascending=True) #Conteo
		ListaM['Porcentaje'] = (ListaM['Frecuencia'] / ListaM['Frecuencia'].sum()) #Porcentaje
		ListaM = ListaM.rename(columns={0 : 'Item'})
		st.header("**Nueva lista de elementos**")
		st.write(ListaM)
		st.header("**Grafico de barras**") # Se genera un gráfico de barras
		plt.figure(figsize=(16,20), dpi=300)
		plt.ylabel('Item')
		plt.xlabel('Frecuencia')
		plt.barh(ListaM['Item'], width=ListaM['Frecuencia'], color='blue')
		st.pyplot()
		#Se crea una lista de listas a partir del dataframe y se remueven los 'NaN'
		#level=0 especifica desde el primer índice
		NuevaLista = df_nh.stack().groupby(level=0).apply(list).tolist()
		
	if enter_hA: 
		st.title("**Reglas de Asosiación**")
		st.header("**Algoritmo: `Apriori`**")
		NuevaLista = df_nh.stack().groupby(level=0).apply(list).tolist()
		ReglasC1 = apriori(NuevaLista, min_support=support, min_confidence=confidence, min_lift=litf)
		ResultadosC1 = list(ReglasC1)
		st.header("**Número de reglas**")
		st.header(len(ResultadosC1))
		st.header("**Data Frame Rules**")
		NuevaLista = df_nh.stack().groupby(level=0).apply(list).tolist()
		ReglasC1 = apriori(NuevaLista, min_support=support, min_confidence=confidence, min_lift=litf)
		ResultadosC1 = list(ReglasC1)
		for item in ResultadosC1:
			#El primer índice de la lista
			Emparejar = item[0]
			items = [x for x in Emparejar]
			st.text("Regla: " + str(item[0]))
			#El segundo índice de la lista
			st.text("Soporte: " + str(item[1]))
			#El tercer índice de la lista
			st.text("Confianza: " + str(item[2][0][2]))
			st.text("Lift: " + str(item[2][0][3])) 
			st.text("=====================================") 

	if impReglas:
		st.title("**Reglas de Asosiación**")
		st.header("**Algoritmo: `Apriori`**")
		st.header("**Data Frame Rules**")
		NuevaLista = df_nh.stack().groupby(level=0).apply(list).tolist()
		ReglasC1 = apriori(NuevaLista, min_support=support, min_confidence=confidence, min_lift=litf)
		ResultadosC1 = list(ReglasC1)
		for item in ResultadosC1:
			#El primer índice de la lista
			Emparejar = item[0]
			items = [x for x in Emparejar]
			st.text("Regla: " + str(item[0]))
			#El segundo índice de la lista
			st.text("Soporte: " + str(item[1]))
			#El tercer índice de la lista
			st.text("Confianza: " + str(item[2][0][2]))
			st.text("Lift: " + str(item[2][0][3])) 
			st.text("=====================================") 
	if enterRegla:
		st.title("**Reglas de Asosiación**")
		st.header("**Algoritmo: `Apriori`**")
		NuevaLista = df_nh.stack().groupby(level=0).apply(list).tolist()
		ReglasC1 = apriori(NuevaLista, min_support=support, min_confidence=confidence, min_lift=litf)
		ResultadosC1 = list(ReglasC1)
		st.header("**Regla**")
		st.header(reglaEx)
		st.text(ResultadosC1[reglaEx-1])

#######################Arbol pronostico
	if ResultadosAB:
		st.title("**Pronostico: Árbol de Decición y Bosques Aleatorios**")
		st.header("**Fuerza del Concreto, resultados del entrenamiento**")
		X = np.array(df[['Cement', 'Blast Furnace Slag','Fly Ash', 'Water','Superplasticizer', 'Coarse Aggregate','Fine Aggregate', 'Age']])
		Y = np.array(df[['Strength']])
		X_train, X_test, Y_train, Y_test = model_selection.train_test_split(X, Y, test_size = 0.2, random_state = 1234, shuffle = True)
		PronosticoAD = DecisionTreeRegressor(max_depth=8, min_samples_split=4, min_samples_leaf=2, random_state=0)
		PronosticoAD.fit(X_train, Y_train)
		PronosticoBA = RandomForestRegressor(n_estimators=100, max_depth=8, min_samples_split=4, min_samples_leaf=2, random_state=0)
		PronosticoBA.fit(X_train, Y_train) 
		Y_PronosticoA = PronosticoAD.predict(X_test)
		Y_PronosticoB = PronosticoBA.predict(X_test)
		###Arbol  de Decision
		#Se calcula la exactitud promedio de la validación
		Arbol=r2_score(Y_test, Y_PronosticoA)
		st.header(f"Score Arbol de Decision: `{Arbol}`")
		###Bosque Aleatorio
		#Se calcula la exactitud promedio de la validación
		BA=r2_score(Y_test, Y_PronosticoB)
		st.header(f"Score Bosque Aleatorio: `{BA}`")
		st.header("**`Entrenamiento del modelo realizado, introduce los datos en la barra lateral para hacer un nuevo pronostico`**")
	if enterDatosAB:
		st.title("**Pronostico Árbol de Decición y Bosques Aleatorios**")
		st.header("**Fuerza del Concreto, resultados del entrenamiento**")
		X = np.array(df[['Cement', 'Blast Furnace Slag','Fly Ash', 'Water','Superplasticizer', 'Coarse Aggregate','Fine Aggregate', 'Age']])
		Y = np.array(df[['Strength']])
		X_train, X_test, Y_train, Y_test = model_selection.train_test_split(X, Y, test_size = 0.2, random_state = 1234, shuffle = True)
		PronosticoAD = DecisionTreeRegressor(max_depth=8, min_samples_split=4, min_samples_leaf=2, random_state=0)
		PronosticoAD.fit(X_train, Y_train)
		PronosticoBA = RandomForestRegressor(n_estimators=100, max_depth=8, min_samples_split=4, min_samples_leaf=2, random_state=0)
		PronosticoBA.fit(X_train, Y_train) 
		Y_PronosticoA = PronosticoAD.predict(X_test)
		Y_PronosticoB = PronosticoBA.predict(X_test)
		st.header("**`Resultado obtenido`**")
		FuerzaConcreto = pd.DataFrame({'Cement':[Cement],
                                    'Blast Furnace Slag':[Blast_Furnace_Slag], 
                                    'Fly Ash':Fly_Ash,
                                    'Water':[Water],
                                    'Superplasticizer':[Superplasticizer],
                                    'Coarse Aggregate':[Coarse_Aggregate],
                                    'Fine Aggregate':[Fine_Aggregate],
                                    'Age':[Age]})
		PronosticoArbol=PronosticoAD.predict(FuerzaConcreto)
		pronosticoBosques=PronosticoBA.predict(FuerzaConcreto)
		st.write(f"Pronostico de la fuerza el concreto por medio de un Árbol de Decisión: `{PronosticoArbol}` kilo Newtons")
		st.write(f"Pronostico de la fuerza el concreto por medio de un Bosque Aleatorio: `{pronosticoBosques}` kilo Newtons")
		
	if ResultadosAB_2:
		st.title("**Clasificación: Árbol de Decición y Bosques Aleatorios**")
		st.header("**Canal de distribución de Whosale, resultados del entrenamiento**")
		Customer = df.replace({1: 0, 2: 1, 3:2})
		st.header("Separación de los dos tipos de canal")
		st.write("#0:Horeca (Hotel/Restaurante/Café)")
		st.write("#1:Retail u Otro")
		st.write(Customer.groupby('Channel').size())
		X = np.array(Customer[['Region', 'Fresh', 'Milk','Grocery','Frozen', 'Detergents_Paper','Delicassen']])
		Y = np.array(Customer[['Channel']])
		X_train, X_validation, Y_train, Y_validation = model_selection.train_test_split(X, Y, test_size = 0.2,random_state = 1234,shuffle = True)
		ClasificacionAD = DecisionTreeClassifier(random_state=0, min_samples_leaf=2)
		#ClasificacionAD = DecisionTreeClassifier(max_depth=8, min_samples_split=4, min_samples_leaf=1)
		ClasificacionAD.fit(X_train, Y_train)
		###Bosque
		#ClasificacionBA = RandomForestClassifier(random_state=0,n_estimators=105)
		#ClasificacionBA.fit(X_train, Y_train)
		#para el mejor modelo es con 105 estimadores 94.74%
		ClasificacionBA = RandomForestClassifier(n_estimators=100, max_depth=8, min_samples_split=4, min_samples_leaf=2, random_state=0)
		ClasificacionBA.fit(X_train, Y_train)
		###Arbol  de Decision
		#Se calcula la exactitud promedio de la validación
		Arbol=ClasificacionAD.score(X_validation, Y_validation)
		st.header(f"Score Arbol de Decision: `{Arbol}`")
		###Bosque Aleatorio
		#Se calcula la exactitud promedio de la validación
		BA=ClasificacionBA.score(X_validation, Y_validation)
		st.header(f"Score Bosque Aleatorio: `{BA}`")
	if enterDatosAB_2:
		st.title("**Clasificación: Árbol de Decición y Bosques Aleatorios**")
		st.header("**Canal de distribución de Whosale, resultados del entrenamiento**")
		Customer = df.replace({1: 0, 2: 1, 3:2})
		st.header("Separación de los dos tipos de canal")
		st.header("#0:Horeca (Hotel/Restaurante/Café)")
		st.header("#1:Retail u Otro")
		st.header("**`Resultado obtenido`**")
		X = np.array(Customer[['Region', 'Fresh', 'Milk','Grocery','Frozen', 'Detergents_Paper','Delicassen']])
		Y = np.array(Customer[['Channel']])
		X_train, X_validation, Y_train, Y_validation = model_selection.train_test_split(X, Y, test_size = 0.2,random_state = 1234,shuffle = True)
		ClasificacionAD = DecisionTreeClassifier(random_state=0, min_samples_leaf=2)
		#ClasificacionAD = DecisionTreeClassifier(max_depth=8, min_samples_split=4, min_samples_leaf=1)
		ClasificacionAD.fit(X_train, Y_train)
		###Bosque
		#ClasificacionBA = RandomForestClassifier(random_state=0,n_estimators=105)
		#ClasificacionBA.fit(X_train, Y_train)
		#para el mejor modelo es con 105 estimadores 94.74%
		ClasificacionBA = RandomForestClassifier(n_estimators=100, max_depth=8, min_samples_split=4, min_samples_leaf=2, random_state=0)
		ClasificacionBA.fit(X_train, Y_train)
		NewCustomer = pd.DataFrame({'Region': [Region], 
                            'Fresh': [Fresh], 
                            'Milk': [Milk], 
                            'Grocery': [Grocery], 
                            'Frozen': [Frozen], 
                            'Detergents_Paper': [Detergents_Paper],
                            'Delicassen':[Delicassen]})
		ClasificacionArbol=ClasificacionAD.predict(NewCustomer)
		ClasificacionBosque=ClasificacionBA.predict(NewCustomer)
		st.write(f"Clasificacion del canal de distribución por medio de un Árbol de Decisión: `{ClasificacionArbol}` ")
		st.write(f"Clasificacion del canal de distribución por medio de un Bosque Aleatorio: `{ClasificacionBosque}` ")



#Con 6 componentes se tiene el 89% de varianza acumulada y con 7 el 93%
else:
	st.info('Esperando por el archivo CSV')
	#if st.button('Presione para usar su archivo')


