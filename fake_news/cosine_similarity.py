import numpy as np
from sklearn.metrics.pairwise import cosine_similarity
from itertools import permutations 


new_dict = {}
with open('model.nepali.vec') as nepali:
	for line in nepali:
		count = 0
		temp = np.empty([100], dtype=float)
		key = ""
		for  i in line.split():
			if count == 0:
				key = i
				count += 1
			else:
				temp[count-1] = (float(i))
				count += 1
		new_dict[key] = temp



englishMetrics = open("nepaliMetricsModel","w+")
with open('head.clean.corpus.ne') as english:
	for line in english:

		temp = []

		for i in line.split():
			temp.append(i)
	
		total = 0
		array = np.array(list(temp))
		if(len(temp)>=2):
			perm = permutations(temp, 2)
			array = np.array(list(perm))
			for i in array:
				if(i[0] in new_dict and i[1] in new_dict):
					first = new_dict[i[0]]
					second = new_dict[i[1]]
					first = first.reshape(1,100)
					second = second.reshape(1,100)
					cos = cosine_similarity(first, second)
					total += cos[0][0]
		
			averageCosineSimilarity = total/(len(array))
			englishMetrics.write(str(averageCosineSimilarity))
			englishMetrics.write(" ")
		else:
			englishMetrics.write("0 ")
		
		englishMetrics.write("\n")

englishMetrics.close()




		##End of cosine similarity metric,  averageCosineSimilarity returns the average 
		#cosine similarity for each sentence


