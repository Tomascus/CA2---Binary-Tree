#include "pch.h"
#include "CppUnitTest.h"
#include "../CA2 - Binary Tree/BinaryTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//These tests based on the provided sample code tests
namespace TestBinaryTree
{
	TEST_CLASS(TestBinaryTree)
	{
		/*
			This test ensures a node is created at the root when
			an element is added to an empty binary tree
		*/
		TEST_METHOD(TestAddToEmptyTree)
		{
			BinaryTree<int> tree;
			tree.add(1);
			Assert::IsNotNull(tree.root);
			Assert::AreEqual(1, tree.root->getItem());
		}
		/*
		This test ensures a node is created on the left branch
		when value is less than root.
		*/
		TEST_METHOD(TestAddToRootLeft)
		{
			BinaryTree<int> tree;
			tree.add(2);
			tree.add(1);
			Assert::IsNotNull(tree.root);
			Assert::AreEqual(2, tree.root->getItem());
			BSTNode<int>* left = tree.root->getLeft();
			Assert::IsNotNull(left);
			Assert::AreEqual(1, left->getItem());
		}
		/*
		This test ensures a node is created on the right branch
		when value is less than root.
		*/
		TEST_METHOD(TestAddToRootRight)
		{
			BinaryTree<int> tree;
			tree.add(2);
			tree.add(3);
			Assert::IsNotNull(tree.root);
			Assert::AreEqual(2, tree.root->getItem());
			BSTNode<int>* right = tree.root->getRight();
			Assert::IsNotNull(right);
			Assert::AreEqual(3, right->getItem());
		}

		/*
		Test the count function for empty tree
		*/

		TEST_METHOD(TestCountOnEmpty)
		{
			BinaryTree<int> tree;
			Assert::AreEqual(0, tree.count());
		}
		/*
		Test the count function for full tree
		to test this we will use the following tree
		   4
		  / \
		 2   6
		/ \ / \
		1 3 5  7
		*/

		TEST_METHOD(TestCountOnFullTree)
		{
			BinaryTree<int> tree;
			tree.add(4);
			tree.add(2);
			tree.add(6);
			tree.add(1);
			tree.add(3);
			tree.add(5);
			tree.add(7);

			Assert::AreEqual(7, tree.count());
		}

		/*
		Test the remove function to try and remove an item not found
		to test this we will use the following tree
		   4
		  / \
		 2   6
		/ \ / \
		1 3 5  7
		*/

		TEST_METHOD(TestRemoveItemNotPresent)
		{
			BinaryTree<int> tree;
			tree.add(4);
			tree.add(2);
			tree.add(6);
			tree.add(1);
			tree.add(3);
			tree.add(5);
			tree.add(7);
			Assert::AreEqual(7, tree.count());
			tree.remove(8);
			Assert::AreEqual(7, tree.count());
			Assert::AreEqual(4, tree.root->getItem());
			Assert::AreEqual(2, tree.root->getLeft()->getItem());
			Assert::AreEqual(6, tree.root->getRight()->getItem());
			BSTNode<int>* left = tree.root->getLeft();
			BSTNode<int>* right = tree.root->getRight();
			Assert::AreEqual(1, left->getLeft()->getItem());
			Assert::AreEqual(3, left->getRight()->getItem());
			Assert::AreEqual(5, right->getLeft()->getItem());
			Assert::AreEqual(7, right->getRight()->getItem());
		}

		/*
		Test the remove function to try and remove a leaf node
		to test this we will use the following tree
		4
		/ \
		2   6
		/ \ / \
		1 3 5  7
		*/

		TEST_METHOD(TestRemoveLeafNode)
		{
			BinaryTree<int> tree;
			tree.add(4);
			tree.add(2);
			tree.add(6);
			tree.add(1);
			tree.add(3);
			tree.add(5);
			tree.add(7);
			Assert::AreEqual(7, tree.count());
			tree.remove(5);
			Assert::AreEqual(6, tree.count());
			Assert::AreEqual(4, tree.root->getItem());
			Assert::AreEqual(2, tree.root->getLeft()->getItem());
			Assert::AreEqual(6, tree.root->getRight()->getItem());
			BSTNode<int>* left = tree.root->getLeft();
			BSTNode<int>* right = tree.root->getRight();
			Assert::AreEqual(1, left->getLeft()->getItem());
			Assert::AreEqual(3, left->getRight()->getItem());
			Assert::IsNull(right->getLeft());
			Assert::AreEqual(7, right->getRight()->getItem());
		}

		/*
		Test the remove function to try and remove a node with one child to the right
		to test this we will use the following tree
		  4
		 / \
		 2   6
		/ \ / \
		1   5  7
				\
				 8
		*/

		TEST_METHOD(TestRemoveNodeWithOneChild)
		{
			BinaryTree<int> tree;
			tree.add(4);
			tree.add(2);
			tree.add(6);
			tree.add(1);
			tree.add(5);
			tree.add(7);
			tree.add(8);
			Assert::AreEqual(7, tree.count());
			tree.remove(7);
			Assert::AreEqual(6, tree.count());
			Assert::AreEqual(4, tree.root->getItem());
			Assert::AreEqual(2, tree.root->getLeft()->getItem());
			Assert::AreEqual(6, tree.root->getRight()->getItem());
			BSTNode<int>* left = tree.root->getLeft();
			BSTNode<int>* right = tree.root->getRight();
			Assert::AreEqual(1, left->getLeft()->getItem());
			Assert::AreEqual(5, right->getLeft()->getItem());
			Assert::AreEqual(8, right->getRight()->getItem());
		}
		/*
		Test the remove function to try and remove a leaf node
		to test this we will use the following tree
		 4
		/ \
		2   6
		/ \ / \
		1 3 5  7
		*/

		TEST_METHOD(TestRemoveNodeWithTwoChildren)
		{
			BinaryTree<int> tree;
			tree.add(4);
			tree.add(2);
			tree.add(6);
			tree.add(1);
			tree.add(3);
			tree.add(5);
			tree.add(7);
			Assert::AreEqual(7, tree.count());
			tree.remove(2);
			Assert::AreEqual(6, tree.count());
			Assert::AreEqual(4, tree.root->getItem());
			Assert::AreEqual(3, tree.root->getLeft()->getItem());
			Assert::AreEqual(6, tree.root->getRight()->getItem());
			BSTNode<int>* left = tree.root->getLeft();
			BSTNode<int>* right = tree.root->getRight();
			Assert::AreEqual(1, left->getLeft()->getItem());
			Assert::IsNull(left->getRight());
			Assert::AreEqual(5, right->getLeft()->getItem());
			Assert::AreEqual(7, right->getRight()->getItem());
		}

		/*
		Test the remove function to try and a node with multiple children
		to test this we will use the following tree:

				   8
				/    \
			   /      \
			  /        \
			 4          12
			/ \        /   \
		   2   6      10   14
		  / \ / \    / \  / \
		 1  3 5  7  9  11 13 15

		 When we remove a node in the middle of the tree, the algorithm
		 should move the next lowest item up to the place of the removed node.
		 In this case 13 will be moved up to the place of 12
		*/

		TEST_METHOD(TestRemoveNodeWithMultipleChildren)
		{
			BinaryTree<int> tree;
			tree.add(8);
			tree.add(4);
			tree.add(12);
			tree.add(2);
			tree.add(6);
			tree.add(1);
			tree.add(3);
			tree.add(5);
			tree.add(7);
			tree.add(10);
			tree.add(14);
			tree.add(9);
			tree.add(11);
			tree.add(13);
			tree.add(15);
			Assert::AreEqual(15, tree.count());

			Assert::IsNotNull(tree.root->getRight()->getRight()->getLeft());
			Assert::AreEqual(13, tree.root->getRight()->getRight()->getLeft()->getItem());
			tree.remove(12);
			Assert::AreEqual(14, tree.count());
			Assert::AreEqual(13, tree.root->getRight()->getItem());
			Assert::IsNull(tree.root->getRight()->getRight()->getLeft());
		}
	};



}