cmake_minimum_required(VERSION 3.20)
project(lab_5e C)

set(CMAKE_C_STANDARD 99)

add_executable(lab_5e main.c
        libs/string/string_.c
        libs/string/string_.h

        libs/string/tasks/1_digitToStartTransform.c
        libs/string/tasks/1_digitToStartTransform.h

        libs/string/tasks/tests.c
        libs/string/tasks/tests.h

        libs/string/tasks/2_removeAdjacentEqualLetters.c
        libs/string/tasks/2_removeAdjacentEqualLetters.h

        libs/string/tasks/3_getWord.c
        libs/string/tasks/3_getWord.h

        libs/string/tasks/4_replaceNumberDigitsBySpace.c
        libs/string/tasks/4_replaceNumberDigitsBySpace.h

        libs/string/tasks/5_replace.c
        libs/string/tasks/5_replace.h

        libs/string/tasks/6_isOrderedWord.c
        libs/string/tasks/6_isOrderedWord.h

        libs/string/tasks/7_outputReverse.c
        libs/string/tasks/7_outputReverse.h

        libs/string/tasks/8_countPalindroms.c
        libs/string/tasks/8_countPalindroms.h

        libs/string/tasks/9_wordAlternation.c
        libs/string/tasks/9_wordAlternation.h

        libs/string/tasks/10_reverseWordInString.c
        libs/string/tasks/10_reverseWordInString.h

        libs/string/tasks/11_printWordBeforeFirstWordWithA.c
        libs/string/tasks/11_printWordBeforeFirstWordWithA.h

        libs/string/tasks/12_lastCommonWord.c
        libs/string/tasks/12_lastCommonWord.h

        libs/string/tasks/13_haveSameWord.c
        libs/string/tasks/13_haveSameWord.h

        libs/string/tasks/15_differentFromTheLastWord.c
        libs/string/tasks/15_differentFromTheLastWord.h

        libs/string/tasks/16_lastCommonWords.c
        libs/string/tasks/16_lastCommonWords.h

        libs/string/tasks/18_padTheSmallerString.c
        libs/string/tasks/18_padTheSmallerString.h
        )
