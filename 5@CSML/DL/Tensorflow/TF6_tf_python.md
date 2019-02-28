
    import tensorflow as tf
    import numpy as NP
    import scipy 
    import scipy.stats
    import os, sys

    def myAdd(a,b):
        c = a + b
        c = NP.float32(c)
        return c


    def caluHistogram(p, q):
        hist1, _ = (list(NP.histogram(p, bins=100, density=True)))
        hist2, _ = (list(NP.histogram(q, bins=100, density=True)))
        # hist1 = list(map(float, hist1))
        # hist2 = list(map(float, hist2))
        return hist1, hist2


    def JSD(p, q):
        p /= p.sum()
        q /= q.sum()
        m = (p + q)/2
        result = (scipy.stats.entropy(p, m) + scipy.stats.entropy(q, m)) / 2
        result = NP.float32(result)
        return result

    def KLD(p, q):
        p = NP.asarray(p, dtype=NP.float32)
        q = NP.asarray(q, dtype=NP.float32)
        result = NP.sum(NP.where(p != 0, p*NP.log(p/q), 0))
        result = NP.float32(result)
        return result

    def test1():
        a = tf.placeholder(tf.float32, shape=(28,28))
        b = tf.placeholder(tf.float32, shape=(28,28))

        c = tf.py_func(myAdd,inp=[a, b], Tout=tf.float32 )

        print(a.shape, b.shape, c.shape)

        with tf.Session() as sess:
            feed_a = NP.random.rand(28,28)
            feed_b = NP.random.rand(28,28)
            result = sess.run(c, feed_dict={a: feed_a, b: feed_b})
            print(result)

    def test2():
        a = tf.placeholder(tf.float32, shape=(28,28))
        b = tf.placeholder(tf.float32, shape=(28,28))
        hist1, hist2 = tf.py_func(caluHistogram, inp=[a, b], Tout=[tf.float64, tf.float64])
        js_distance = tf.py_func(JSD, inp = [hist1, hist2], Tout=tf.float32)
        with tf.Session() as sess:
            feed_a = NP.random.rand(28,28)
            feed_b = NP.random.rand(28,28)
            result = sess.run(js_distance, feed_dict={a: feed_a, b: feed_b})
            sys.stdout.write("######################################\n")
            print(result)
            sys.stdout.write("######################################\n")

    def test3():
        a = tf.placeholder(tf.float32, shape=(28,28))
        b = tf.placeholder(tf.float32, shape=(28,28))
        hist1, hist2 = tf.py_func(caluHistogram, inp=[a, b], Tout=[tf.float64, tf.float64])
        kl_distance = tf.py_func(KLD, inp = [hist1, hist2], Tout=tf.float32)
        with tf.Session() as sess:
            feed_a = NP.random.rand(28,28)
            feed_b = NP.random.rand(28,28)
            result = sess.run(kl_distance, feed_dict={a: feed_a, b: feed_b})
            sys.stdout.write("######################################\n")
            print(result)
            sys.stdout.write("######################################\n")
        
    if __name__ == "__main__":
        # test1()
        #test2()
        test3()
