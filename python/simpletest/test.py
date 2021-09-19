import unittest
from mathtest import add, minus


class TestMathFunc(unittest.TestCase):
    """ Test math function """

    def test_add(self):
        """ Test method add(a,b) """
        self.assertEqual(3, add(1, 2))
        self.assertNotEqual(3, add(2, 2))

    def test_minus(self):
        """ Test method test minus(a,b) """
        self.assertEqual(1, minus(3, 2))


if __name__ == '__main__':
    unittest.main()
