Microbiologists estimating the number of bacteria in a sample that contains bacteria that do
not grow well on solid media may use a statistical technique called the most probable number
(MPN) method. Each of five tubes of nutrient medium receives 10 ml of the sample. A
second set of five tubes receives 1 ml of sample per tube, and in each of a third set of five
tubes only 0.1 ml of sample is placed. Each tube in which bacterial growth is observed is
recorded as a positive, and the numbers for the three groups are combined to create a triplet
such as 5-2-1, which means that all five tubes receiving 10 ml of sample show bacterial
growth, only two tubes in the 1-ml show growth, and only one of the 0.1-ml group is positive.
Write an application in C++ for generating explanations of combination-of-positives triplet.

You are required to design a structure type to represent one row of the MPN table above.
Load the MPN table from a file into an array of structures that can store details of a
maximum of 125 MPN data.

After building the MPN data list (array of structures), display a menu with the following
options:

(a) List – Display the MPN data in the array of structures forward. Each display should contain an appropriate heading and column captions.

(b) Search – This is allow user to search for a MPN data in the MPN data list by using the combination-of-positives triplet and generate a message such as:
    For 5-2-1, MPN = 70; 95% of samples contain between 30 and 210 bacterial/ml.

(c) Insert – This is to allow user to insert a non-duplicate combination-of-positives triplet data into the MPN data list by getting from the user a combination of-positives triplet and the associated most probable number and the lower and upper bounds of the 95 % confidence range. Re-sort the MPN data list in ascending order on the combination-of-positives triplet.

(d) Update – This is to allow user to update the associated most probable number and the lower and upper bounds of the 95 percent confidence range in the MPN data list by using the combination-of-positives triplet. You should reuse the function defined for Search operation.

(e) Query - This search function can search for same number of positive tubes in each group in the MPN data list (array of structures). For example, the user wants to find out all combinations that have 3 tubes in the 1-ml group show growth.

(f) Exit – Stop the program. The program will write the updated data in the MPN data list (array of structures) to the text file.

Prepare the necessary data file for building the data structures needed in your application.
You may give additional assumptions for your application. To make your program more
robust and avoid problems at run time, do as much status/error checking as you can in your
program. You may also add more features and/or record more details of MPN data in your
program for enhancement.
