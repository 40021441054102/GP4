# ifndef RK_GRAPHICS_PROJECT_4_CONFIGS
    /**
     * @file Configs4.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief Configuration File for Clock
     * @def RK_GRAPHICS_PROJECT_4_CONFIGS
     * @date 2024-12-05
     */
    # define RK_GRAPHICS_PROJECT_4_CONFIGS
    //-- Behave According to Android or Linux
    # ifdef __ANDROID__
        /**
         * @brief Clock Window Width
         * @def RK_CLOCK_WINDOW_WIDTH
         */
        # define RK_CLOCK_WINDOW_WIDTH 1080
        /**
         * @brief Clock Window Height
         * @def RK_CLOCK_WINDOW_HEIGHT
         */
        # define RK_CLOCK_WINDOW_HEIGHT 2400
        /**
         * @brief Clock Radius
         * @def RK_CLOCK_RADIUS
         */
        # define RK_CLOCK_RADIUS 489
    # else
        /**
         * @brief Clock Window Width
         * @def RK_CLOCK_WINDOW_WIDTH
         */
        # define RK_CLOCK_WINDOW_WIDTH 2200
        /**
         * @brief Clock Window Height
         * @def RK_CLOCK_WINDOW_HEIGHT
         */
        # define RK_CLOCK_WINDOW_HEIGHT 1440
        /**
         * @brief Clock Radius
         * @def RK_CLOCK_RADIUS
         */
        # define RK_CLOCK_RADIUS 600
    # endif // __ANDROID__
    /**
     * @brief Clock Hour Format
     * @def RK_CLOCK_HOUR_FORMAT_AM_PM
     * @note true for AM/PM and false for 24-Hour
     */
    # define RK_CLOCK_HOUR_FORMAT_AM_PM false
    /**
     * @brief Clock Show UTC Time
     * @def RK_CLOCK_SHOW_UTC_TIME
     * @note true for UTC Time and false for Local Time
     */
    # define RK_CLOCK_SHOW_UTC_TIME false
    /**
     * @brief Clock Hour Hand Length
     * @def RK_CLOCK_HAND_HOUR_LENGTH
     */
    # define RK_CLOCK_HAND_HOUR_LENGTH RK_CLOCK_RADIUS * 0.4
    /**
     * @brief Clock Hour Hand Text Length
     * @def RK_CLOCK_HAND_HOUR_TEXT_LENGTH
     */
    # define RK_CLOCK_HAND_HOUR_TEXT_LENGTH RK_CLOCK_HAND_HOUR_LENGTH * 0.6
    /**
     * @brief Clock Minute Hand Length
     * @def RK_CLOCK_HAND_MINUTE_LENGTH
     */
    # define RK_CLOCK_HAND_MINUTE_LENGTH RK_CLOCK_RADIUS * 0.7
    /**
     * @brief Clock Minute Hand Text Length
     * @def RK_CLOCK_HAND_MINUTE_TEXT_LENGTH
     */
    # define RK_CLOCK_HAND_MINUTE_TEXT_LENGTH RK_CLOCK_HAND_MINUTE_LENGTH * 0.6
    /**
     * @brief Clock Second Hand Length
     * @def RK_CLOCK_HAND_SECOND_LENGTH
     */
    # define RK_CLOCK_HAND_SECOND_LENGTH RK_CLOCK_RADIUS * 0.86
    /**
     * @brief Clock Second Hand Text Length
     * @def RK_CLOCK_HAND_SECOND_TEXT_LENGTH
     */
    # define RK_CLOCK_HAND_SECOND_TEXT_LENGTH RK_CLOCK_HAND_SECOND_LENGTH * 0.7
    /**
     * @brief Clock Millisecond Hand Length
     * @def RK_CLOCK_HAND_MILLISECOND_LENGTH
     */
    # define RK_CLOCK_HAND_MILLISECOND_LENGTH RK_CLOCK_RADIUS * 0.95
    /**
     * @brief Clock Millisecond Hand Text Length
     * @def RK_CLOCK_HAND_MILLISECOND_TEXT_LENGTH
     */
    # define RK_CLOCK_HAND_MILLISECOND_TEXT_LENGTH RK_CLOCK_HAND_MILLISECOND_LENGTH * 0.6
    /**
     * @brief Clock Show Milliseconds by Polygon
     * @note true for Polygon and false for Line
     * @def RK_CLOCK_HAND_MILLISECOND_SHOW
     */
    # define RK_CLOCK_HAND_MILLISECOND_SHOW_WITH_POLYGON true
    /**
     * @brief Clock Miliseconds Padding Degree for Visual Effect
     * @def RK_CLOCK_HAND_MILLISECOND_PADDING_DEGREE
     */
    # define RK_CLOCK_HAND_MILLISECOND_PADDING_DEGREE 2.0
    /**
     * @brief Clock Label Background Radius
     * @def RK_CLOCK_LABEL_BACKGROUND_RADIUS
     */
    # define RK_CLOCK_LABEL_BACKGROUND_RADIUS 30
    /**
     * @brief Clock Label Rotate
     * @note true for Rotate and false for Static
     * @def RK_CLOCK_LABEL_ROTATE
     */
    # define RK_CLOCK_LABEL_ROTATE true
# endif // RK_GRAPHICS_PROJECT_4_CONFIGS