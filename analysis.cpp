//***************************************************************************
//
// Student name: Moaz Zawra
//
// Student number: 200449085
//
// Dr. Cory Butz
//
// Assignment number: CS 110 Assignment #4
//
// Program name: analysis.cpp
//
// Last date modified: April 04, 2021
//
// ---------------------------- Problem Statement ------------------------------
//
// This C++ program examines both hemoglobin genes for each of four people, with each gene consisting of 444 DNA bases (A,C,G,T). These are the four bases (letters) that make up DNA.
//
// ---------------------------- Input and Output --------------------------------
//
// Input: DNA of the two hemoglobin genes of four people. The input file (dna.txt) contains the gene DNA information in this order:
//      geneA1
//      geneA2
//      geneB1
//      geneB2
//      geneC1
//      geneC2
//      geneD1
//      geneD2
// Note: 1 and 2 denote the first and second gene, and A,B,C,D denote people.
//
// Output: In the output file, (DNAanalysis.txt), it is indicated whether each person is anemic, a carrier, or normal and whether any of the four individuals are related.
//
// ------------------------------ Main Algorithm ---------------------------------
//
// Main algorithm: declare character arrays with size 444 to the sickle hemoglobin genes
//                 declare char array with size 3552 to the main variable called "gene_pool" which will read in all the genetic information from the input                file "dna.txt"
//                 get the 20th position from each sickle hemoglobin gene
//                 check if any sickle hemoglobin gene has a T in the 20th position and print a message to the user showing all sickle-cell anemia test                   results regarding the four individuals (A,B,C,D)
//                 get all sickle hemoglobin genes from the input file once more and save it into char arrays to scan them and check if at least one                      hemoglobin gene is shared between any two individuals.
//                 print a message to the user declaring any two individuals that are considered to be related.

//
// ------------------------------ Major Variables ---------------------------------
//
// Major variables: geneA1, geneA2, ..., geneD2 - 1 and 2 denote the first and second gene, and A,B,C,D denote people
//                  gene_pool - character array of size 3552 that holds all the genetic dna information from the input file "dna.txt"
//                  gene_A1, geneA2, ..., gene_D2 - character arrays of size n used to hold the entire genetic data (444 characters) of each person, n is                  initially denoted as 0.
//                  DNA_Bases - this int variable is used to hold the value 444
//                  Max_Char - this int variable is used to hold the value 3552
//
// ------------------------------ Program Limitations ------------------------------
//
// This program is only limited to four different individuals having a total of 3552 characters within their DNA samples. This program only tests for sickle-cell anemia, which is identified by the sickle hemoglobin gene that has a T in the 20th position. The relationship test is only limited to the four individuals who participated in the sickle-cell anemia test.
//
//******************************************************************************

#include <iostream>
#include <fstream>
using namespace std;

bool SameGene(char[], char[], int); // Function prototype

int main()
{
    ifstream inFile;  // declare input file as inFile
    ofstream outFile; // declare output file as outFile

    inFile.open("dna.txt");          // open the input file "dna.txt"
    outFile.open("DNAanalysis.txt"); // open the output file "DNAanalysis.txt"

    if (!inFile) // check for errors regarding the input file
    {
        cout << "Input file did not open successfully" << endl;
        return 1;
    }

    if (!outFile) // check for errors regarding the output file
    {
        cout << "Output file did not open successfully" << endl;
        return 2;
    }

    const int DNA_Bases = 444; // store the value 444 in the const int variable DNA_Bases for ease of use
    const int Max_Char = 3552; // store the value 3552 in the const int variable Max_Char for ease of use
    const int n = 0;           // the value of n is declared as 0 initially

    char geneA1[DNA_Bases];   // this character array of size 444 holds the data for the hemoglobin gene 1 of person A
    char geneA2[DNA_Bases];   // this character array of size 444 holds the data for the hemoglobin gene 2 of person A
    char geneB1[DNA_Bases];   // this character array of size 444 holds the data for the hemoglobin gene 1 of person B
    char geneB2[DNA_Bases];   // this character array of size 444 holds the data for the hemoglobin gene 2 of person B
    char geneC1[DNA_Bases];   // this character array of size 444 holds the data for the hemoglobin gene 1 of person C
    char geneC2[DNA_Bases];   // this character array of size 444 holds the data for the hemoglobin gene 2 of person C
    char geneD1[DNA_Bases];   // this character array of size 444 holds the data for the hemoglobin gene 1 of person D
    char geneD2[DNA_Bases];   // this character array of size 444 holds the data for the hemoglobin gene 2 of person D
    char gene_pool[Max_Char]; // this char array of size 3552 holds the entire genetic data from the input file "dna.txt"

    // size n is initially declared as 0
    char gene_A1[n];
    char gene_A2[n];
    char gene_B1[n];
    char gene_B2[n];
    char gene_C1[n];
    char gene_C2[n];
    char gene_D1[n];
    char gene_D2[n];

    char gene1[DNA_Bases]; // char array of size 444 used in the subfunction, called SameGene
    char gene2[DNA_Bases]; // char array of size 444 used in the subfunction, called SameGene
                           // bool relation_test; // declare the variable relation_test using the datatype bool to return "true" or "false"

    inFile >> gene_pool; // read in the entire gene information from the input file "dna.txt" and assign it into char gene_pool

    // copy the 20th position value from the char array gene_pool into each respective array corresponding to that gene and person
    for (int i = 0; i < 1; i++)
    {
        inFile.get(gene_pool[19]);
        geneA1[19] = gene_pool[19];

        inFile.get(gene_pool[463]);
        geneA2[19] = gene_pool[463];

        inFile.get(gene_pool[907]);
        geneB1[19] = gene_pool[907];

        inFile.get(gene_pool[1351]);
        geneB2[19] = gene_pool[1351];

        inFile.get(gene_pool[1795]);
        geneC1[19] = gene_pool[1795];

        inFile.get(gene_pool[2239]);
        geneC2[19] = gene_pool[2239];

        inFile.get(gene_pool[2683]);
        geneD1[19] = gene_pool[2683];

        inFile.get(gene_pool[3127]);
        geneD2[19] = gene_pool[3127];
    }

    outFile << "------------------------ Sickle-Cell Anemia Test Results ----------------------" << endl;
    outFile << endl;

    // check each individual whether they are a carrier, anemic, or normal
    if (geneA1[19] == 'T' && geneA2[19] == 'T')
    {
        outFile << "Person A is anemic" << endl;
    }
    else if (geneA1[19] == 'T' || geneA2[19] == 'T')
    {
        outFile << "Person A is a carrier" << endl;
    }
    else
    {
        outFile << "Person A is normal" << endl;
    }

    if (geneB1[19] == 'T' && geneB2[19] == 'T')
    {
        outFile << "Person B is anemic" << endl;
    }
    else if (geneB1[19] == 'T' || geneB2[19] == 'T')
    {
        outFile << "Person B is a carrier" << endl;
    }
    else
    {
        outFile << "Person B is normal" << endl;
    }

    if (geneC1[19] == 'T' && geneC2[19] == 'T')
    {
        outFile << "Person C is anemic" << endl;
    }
    else if (geneC1[19] == 'T' || geneC2[19] == 'T')
    {
        outFile << "Person C is a carrier" << endl;
    }
    else
    {
        outFile << "Person C is normal" << endl;
    }

    if (geneD1[19] == 'T' && geneD2[19] == 'T')
    {
        outFile << "Person D is anemic" << endl;
    }
    else if (geneD1[19] == 'T' || geneD2[19] == 'T')
    {
        outFile << "Person D is a carrier" << endl;
    }
    else
    {
        outFile << "Person D is normal" << endl;
    }

    // assign the data of each gene to the char array gene_letter#
    for (int i = 0; i < DNA_Bases; i++)
    {
        inFile.get(geneA1[i]);
        inFile.get(geneA2[i]);
        inFile.get(geneB1[i]);
        inFile.get(geneB2[i]);
        inFile.get(geneC1[i]);
        inFile.get(geneC2[i]);
        inFile.get(geneD1[i]);
        inFile.get(geneD2[i]);

        gene_A1[n] = geneA1[i];
        gene_A2[n] = geneA2[i];
        gene_B1[n] = geneB1[i];
        gene_B2[n] = geneB2[i];
        gene_C1[n] = geneC1[i];
        gene_C2[n] = geneC2[i];
        gene_D1[n] = geneD1[i];
        gene_D2[n] = geneD2[i];
    }

    outFile << endl;

    outFile << "--------------------------- Relationship Test Results ---------------------------" << endl;
    outFile << endl;

    // check if any two indivduals are related
    if ((gene_A1[n] || gene_A2[n]) == (gene_B1[n] || gene_B2[n]))
    {
        outFile << "Person A is related to person B" << endl;
    }

    else if ((gene_A1[n] || gene_A2[n]) == (gene_C1[n] || gene_C2[n]))
    {
        outFile << "Person A is related to person C" << endl;
    }

    else if ((gene_A1[n] || gene_A2[n]) == (gene_D1[n] || gene_D2[n]))
    {
        outFile << "Person A is related to person D" << endl;
    }

    else if ((gene_B1[n] || gene_B2[n]) == (gene_C1[n] || gene_C2[n]))
    {
        outFile << "Person B is related to person C" << endl;
    }

    else if ((gene_B1[n] || gene_B2[n]) == (gene_D1[n] || gene_D2[n]))
    {
        outFile << "Person B is related to person D" << endl;
    }

    else if ((gene_C1[n] || gene_C2[n]) == (gene_D1[n] || gene_D2[n]))
    {
        outFile << "Person C is related to person D" << endl;
    }

    else
    {
        outFile << "Non of the four individuals are related" << endl;
    }

    /*
    inFile.close(); // close the input file
    outFile.close(); // close the output file
     */

    return 0;
}
