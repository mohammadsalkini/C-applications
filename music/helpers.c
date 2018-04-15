// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <string.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int nomerator = atoi(fraction);
    int denominator = fraction[2] - '0';

    if (denominator == 8)
    {
        return nomerator;
    }

    if (denominator == 4)
    {
        return nomerator * 2;
    }

    return nomerator * 4;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{

    int note_length = strlen(note);
    int octave;
    string note1 [12] = {"A0", "Bb", "B0", "C0", "Db", "D0", "Eb", "E0", "F0", "Gb", "G0", "Ab"};
    string note2 [12] = {"A0", "A#", "B0", "C0", "C#", "D0", "D#", "E0", "F0", "F#", "G0", "G#"};
    //n is the number of semitones
    int n;
    float frequency;
    //frequencies A0, A1, A2,...., A8
    double freq_A [] = {27.5, 55, 110, 220, 440, 880, 1760, 3520, 7040};
    char mini_note [2];
    //minimizing note (deleting the octave)
    if (note_length == 3)
    {
        octave = note[2] - '0';
        mini_note[0] = (char)note[0];
        mini_note[1] = (char)note[1];
    }
    //minimizing note (deleting the octave)
    if (note_length == 2)
    {
        octave = note[1] - '0';
        mini_note[0] = (char)note[0];
        mini_note[1] = (char)'0';
    }
    //getting n
    for (int counter = 0; counter < 12; counter++)
    {
        int h = strcmp (note1[counter], mini_note);
        int h2 = strcmp (note2[counter], mini_note);
        if (h == 0 || h2 == 0)
        {
            n = counter;
            break;
        }

    }
    int A = strcmp (mini_note, "A0");
    int Ax = strcmp (mini_note, "A#");
    int Bx = strcmp (mini_note, "Bb");
    int B = strcmp (mini_note, "B0");

    //getting the frecuency
    if (B == 0 || Ax == 0 || Bx == 0)
    {
        frequency = pow(2, n / 12.00) * freq_A[octave];
        frequency =  round (frequency);
    }
    else
    {
        if (A == 0)
        {
            frequency = freq_A[octave];
        }
        else
        {
            frequency = pow(2, n / 12.00) * freq_A[octave - 1];
            frequency =  round (frequency);
        }

    }
    return frequency;

}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    int h = strcmp (s, "");
    //no input
    if (h == false)
    {
        return true;
    }
    //there is input
    return false;
}
