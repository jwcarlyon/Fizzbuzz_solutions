import math

def create_vector_sums(dct):
    vectors = {}
    for doc in dct.values():
        for c in doc:
            if c in vectors:
                vectors[c] = vectors[c] + 1
            else:
                vectors[c] = 1
    return vectors

def doc_vector(doc, dct):
    vector = []
    for term in create_vector_sums(dct).keys():
        vector.append(dct[doc].count(term))
    #vector is a list of term counts in the vector's document
    return vector

def idf_(vectors):
    #idf is the inverse document frequency - each term in a vector has a non-negative idf value
    idf_vecs = {}
    for vec in vectors.keys():
        idf = []
        #each vec references a list of int values in order
        for x in vectors[vec]:
            #x is the term frequency, iterating through the raw vector values
            if x > 0:
                doc_freq = 0
                for val in vectors.values():
                    #checks each vector for a positive value at the position of term x
                    if val[len(idf)] > 0:
                        doc_freq += 1
                tf_idf = (x * math.log((len(vectors) / doc_freq), 10))#tern frequency/invers document frequency
                idf.append(tf_idf)
            else:
                idf.append(.0)
        idf_vecs[vec] = idf
    return idf_vecs

def cosine_len_normalized(idf_vectors):
    normal_vecs = {}
    for vec in idf_vectors.keys():
        #iterating through document vector (double list)
        len_norm = .0
        for x in idf_vectors[vec]:
            len_norm += x * x
        normal_vecs[vec] = list(map(lambda x : (x / math.sqrt(len_norm)), idf_vectors[vec]))
    return normal_vecs

def dot_search(normal_vectors):
    docs = list(normal_vectors.keys())
    vecs = list(normal_vectors.values())
    top = 0
    names = ""
    search = {}
    for i in range(len(docs) - 1):
        #test vecs[i] against vecs[i:]
        for w in vecs[i:]:
            #find dot w * vec[i] sum(i[0] * i[1] for i in zip(K, L))
            dot = sum((x[0] * x[1]) for x in zip(w, vecs[i]))
            #print("debug: {} and {} at: {}".format(docs[vecs.index(w)], docs[i], dot))
            if not(vecs.index(w) == i):
                search["{} and {}".format(docs[vecs.index(w)], docs[i])] = dot * 100
                if dot > top:
                    #names = "{} and {} at: {}".format(docs[vecs.index(w)], docs[i], dot)
                    top = dot #new best combination
    return search
if __name__ == "__main__":
    dct = {"fred" : ['Banana', 'Coffee', 'Coffee', 'Energy Drink'],
        "ralph" : ['Cup Cakes', 'Cigarettes', 'Wine', 'Lighter'],
        "jeff" : ['Coffee', 'Fountain Drink', 'Gum', 'Lighter', 'Propane'],
        "jake" : ['Candy Bar', 'Energy Drink'],
        "brian" : ['Coffee', 'Toy Robot']}

    vectors = {}
    for doc in dct.keys():
        #iterating through names
        vectors[doc] = doc_vector(doc, dct)
    idf_vectors = idf_(vectors)#dictionary with each document's idf vector
    normal_vectors = cosine_len_normalized(idf_vectors)#length normalized document vectors
    #search algorithm - find largest dot product in normal_vectors -
    similarities = dot_search(normal_vectors)
    print("The list's similarity comparisons with percentages: {}".format(similarities))
