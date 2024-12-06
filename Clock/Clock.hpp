# ifndef RK_GRAPHICS_PROJECT_4
    /**
     * @file Clock.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief Ramtin Kosari's Clock - Term 7 Graphics Project 4
     * @date 2024-12-05
     */
    # define RK_GRAPHICS_PROJECT_4
    /**
     * @brief Ramtin Kosari's Clock
     * @def RK_GRAPHICS_PROJECT_CLOCK
     * @note This is Part of Term 7 Graphics Project 4
     */
    # define RK_GRAPHICS_PROJECT_CLOCK
    //-- Check if Project is being Compiled by RKACPB
    # ifdef RKACPB
        //-- Check if Configuration File is Configured
        # ifndef HAS_RKACPB_MODULE_CONFIGS4
            # error "Configuration File is Required for RK Graphics Project 4"
        # endif // RK_GRAPHICS_PROJECT_4_CONFIGS
        //-- Check if RKLogger is Configured
        # ifndef HAS_RKACPB_MODULE_RKLOGGER
            # error "RKLogger is Required for RK Graphics Project 4"
        # endif // HAS_RKACPB_MODULE_RKLOGGER
        //-- Check if RKOGLT is Configured
        # ifndef HAS_RKACPB_MODULE_RKOGLT
            # error "RKOGLT is Required for RK Graphics Project 4"
        # endif // HAS_RKACPB_MODULE_RKOGLT
        //-- Check if Window is Configured
        # ifndef HAS_RKACPB_MODULE_WINDOW
            # error "Window is Required for RK Graphics Project 4"
        # endif // HAS_RKACPB_MODULE_WINDOW
        //-- Check if Line is Configured
        # ifndef HAS_RKACPB_MODULE_LINE
            # error "Line is Required for RK Graphics Project 4"
        # endif // HAS_RKACPB_MODULE_LINE
        //-- Check if Polygon is Configured
        # ifndef HAS_RKACPB_MODULE_POLYGON
            # error "Polygon is Required for RK Graphics Project 4"
        # endif // HAS_RKACPB_MODULE_POLYGON
    # endif // RKACPB
    //-- Include Configuration File
    # ifndef RK_GRAPHICS_PROJECT_4_CONFIGS
        # include "Configs4.hpp"
    # endif // RK_GRAPHICS_PROJECT_4_CONFIGS
    //-- Include RKLogger
    # ifndef RKLOGGER
        # include "RKLogger.hpp"
    # endif // RKLOGGER
    //-- Include RKOGLT
    # ifndef RKOGLT
        # include "RKOGLT.hpp"
    # endif // RKOGLT
    //-- Include Window
    # ifndef SYNESTIA_GRAPHICS_WINDOW
        # include "Window.hpp"
    # endif // SYNESTIA_GRAPHICS_WINDOW
    //-- Include Line
    # ifndef SYNESTIA_GRAPHICS_LINE
        # include "Line.hpp"
    # endif // SYNESTIA_GRAPHICS_LINE
    //-- Include Polygon
    # ifndef SYNESTIA_GRAPHICS_POLYGON
        # include "Polygon.hpp"
    # endif // SYNESTIA_GRAPHICS_POLYGON
    //-- Include Triangle
    # ifndef SYNESTIA_GRAPHICS_TRIANGLE
        # include "Triangle.hpp"
    # endif // SYNESTIA_GRAPHICS_TRIANGLE
    //-- Include Text
    # ifndef SYNESTIA_GRAPHICS_TEXT
        # include "Text.hpp"
    # endif // SYNESTIA_GRAPHICS_TEXT
    //-- Include Glut
    # ifndef __FREEGLUT_H__
        # include <GL/freeglut.h>
    # endif // __FREEGLUT_H__
    //-- Include Thread Library
    # ifndef _GLIBCXX_THREAD
        # include <thread>
    # endif // _GLIBCXX_THREAD
    //-- Include Chrono Library
    # ifndef _GLIBCXX_CHRONO
        # include <chrono>
    # endif // _GLIBCXX_CHRONO
    //-- Include Deque
    # ifndef _GLIBCXX_DEQUE
        # include <deque>
    # endif // _GLIBCXX_DEQUE
    /**
     * @brief Ramtin Kosari's Clock Type
     * @enum RKClockType
     * @note This Enum Defines Different Types of Clocks
     * @param RK_CLOCK_TEST Test Clock
     * @param RK_CLOCK_ANALOG Analog Clock
     * @param RK_CLOCK_DIGITAL Digital Clock
     * @param RK_CLOCK_MODERN Modern Clock
     */
    enum RKClockType {
        RK_CLOCK_TEST,
        RK_CLOCK_ANALOG,
        RK_CLOCK_DIGITAL,
        RK_CLOCK_MODERN
    };
    /**
     * @brief Ramtin Kosari's Clock Label
     * @enum RKClockLabel
     * @note This Enum Defines Different Labels of Clocks
     * @param RK_CLOCK_LABEL_HOUR Hour Label
     * @param RK_CLOCK_LABEL_MINUTE Minute Label
     * @param RK_CLOCK_LABEL_SECOND Second Label
     * @param RK_CLOCK_LABEL_MILLISECOND Millisecond Label
     */
    enum RKClockLabel {
        RK_CLOCK_LABEL_HOUR,
        RK_CLOCK_LABEL_MINUTE,
        RK_CLOCK_LABEL_SECOND,
        RK_CLOCK_LABEL_MILLISECOND
    };
    /**
     * @brief Ramtin Kosari's Clock Class
     * @class RKClock
     */
    class RKClock {
        public:
            /**
             * @brief Window that Displays the Clock
             */
            synwin::SynWindow window = synwin::SynWindow(
                "Synestia Graphics",
                RK_CLOCK_WINDOW_HEIGHT,
                RK_CLOCK_WINDOW_WIDTH
            );
            /**
             * @brief Default Constructor
             */
            RKClock();
            /**
             * @brief Constructor with Clock Type
             * @param type Clock Type
             */
            RKClock(RKClockType type);
            /**
             * @brief Method to Generate Points
             * @param amount Amount of Points
             * @param radius Radius of Points
             * @param color Color of Points
             * @param offset Offset of Points (Degrees)
             * @param counterclockwise Counterclockwise Generation
             * @return std::deque<RKGPoint> List of Points
             */
            std::deque<RKGPoint> generatePoints(
                int amount,
                int radius,
                RKGColor color,
                double offset,
                bool counterclockwise
            );
            /**
             * @brief Method to Generate Background Points
             * @param label Label to Generate Points for
             * @param angle Angle of Center of Background
             * @return std::deque<RKGPoint> List of Points
             */
            std::deque<RKGPoint> generateBGPoints(
                RKClockLabel label,
                double angle,
                std::string text
            );
            /**
             * @brief Method to Draw Labels
             * @param label Label to Draw for
             */
            void drawLabels(RKClockLabel label);
            /**
             * @brief Method to Get Clock Time
             * @param hours Hours
             * @param minutes Minutes
             * @param seconds Seconds
             * @param milliseconds Milliseconds
             */
            void getClockTime(
                int &   hours,
                int &   minutes,
                int &   seconds,
                int &   milliseconds
            );
            /**
             * @brief Method to Draw Hands
             * @param angle_ms Millisecond Hand Angle
             * @param angle_s Second Hand Angle
             * @param angle_m Minute Hand Angle
             * @param angle_h Hour Hand Angle
             */
            void drawHands(
                double angle_ms,
                double angle_s,
                double angle_m,
                double angle_h
            );
    };
# endif // RK_GRAPHICS_PROJECT_4