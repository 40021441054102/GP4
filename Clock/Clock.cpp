# ifndef RK_GRAPHICS_PROJECT_4
    # include "Clock.hpp"
    /**
     * @brief Method to Generate Points
     * @param amount Amount of Points
     * @param radius Radius of Points
     * @param color Color of Points
     * @param offset Offset of Points (Degrees)
     * @param counterclockwise Counterclockwise Generation
     * @return std::deque<RKGPoint> List of Points
     */
    std::deque<RKGPoint> RKClock::generatePoints(int amount, int radius, RKGColor color, double offset = 0, bool counterclockwise = false) {
        //-- Create Queue of Points
        std::deque<RKGPoint> points;
        //-- Generate Points
        for (int i = 0; i < amount; i++) {
            double angle;
            if (counterclockwise) {
                angle = (offset - i * 360.0 / amount) * M_PI / 180.0;
            } else {
                angle = (offset + i * 360.0 / amount) * M_PI / 180.0;
            }
            RKGPoint point;
            point.x = RK_CLOCK_WINDOW_WIDTH / 2 + radius * cos(angle);
            point.y = RK_CLOCK_WINDOW_HEIGHT / 2 + radius * sin(angle);
            point.z = 0;
            point.color = color;
            points.push_back(point);
        }
        //-- Return Points
        return points;
    }
    /**
     * @brief Method to Generate Background Points
     * @param label Label to Generate Points for
     * @param angle Angle of Center of Background
     * @return std::deque<RKGPoint> List of Points
     */
    std::deque<RKGPoint> RKClock::generateBGPoints(RKClockLabel label, double angle, std::string label_text) {
        //-- Define Numbers
        std::string num_hour, num_minute, num_second;
        //-- Define Angles
        RKGDegree hour_label_deg, minute_label_deg, second_label_deg;
        //-- Set Initial Angles
        hour_label_deg.degree = 0;
        hour_label_deg.z = 1;
        minute_label_deg.degree = 0;
        minute_label_deg.z = 1;
        second_label_deg.degree = 0;
        second_label_deg.z = 1;
        //-- Define Color Object for Text Labels
        RKGColor color = {255, 255, 255, 255};
        //-- Define Text Scale
        RKGScale scale = {0.2, 0.2, 0.2};
        //-- Define Hands Points
        RKGPoint center_hour, center_minute, center_second;
        //-- Create Queue of Points
        std::deque<RKGPoint> points;
        //-- Behave According to Label
        switch (label) {
            //-- Generate Background Points for Hour Label
            case RK_CLOCK_LABEL_HOUR: {
                //-- Create Polygon Object
                synshape::Polygon polygon;
                //-- Set Center Point
                center_hour.x = RK_CLOCK_WINDOW_WIDTH / 2 + RK_CLOCK_HAND_HOUR_TEXT_LENGTH * cos(angle * M_PI / 180);
                center_hour.y = RK_CLOCK_WINDOW_HEIGHT / 2 + RK_CLOCK_HAND_HOUR_TEXT_LENGTH * sin(angle * M_PI / 180);
                center_hour.z = 0;
                center_hour.color = {16, 66, 66, 255};
                //-- Generate Points for Hour Label
                for (int i = 0; i < 20; i++) {
                    double angle = (90 - i * 18) * M_PI / 180;
                    RKGPoint point;
                    point.x = center_hour.x + RK_CLOCK_LABEL_BACKGROUND_RADIUS * cos(angle);
                    point.y = center_hour.y + RK_CLOCK_LABEL_BACKGROUND_RADIUS * sin(angle);
                    point.z = 0;
                    point.color = {14, 24, 24, 255};
                    points.push_back(point);
                }
                //-- Draw Background Circle
                polygon.drawPolygon(points, true);
                //-- Set Hour Label Angle
                hour_label_deg.degree = angle;
                //-- Create Point for Centering Text
                RKGPoint center_text;
                if (angle <= 0 && angle > -90) { //-- 1
                    center_text.x = center_hour.x - 15;
                    center_text.y = center_hour.y - 5;
                }
                if  (angle <= -90 && angle > -180) { //-- 2
                    center_text.x = center_hour.x + 10;
                    center_text.y = center_hour.y + 5;
                }
                if (angle <= -180 && angle > -270) { //-- 3
                    center_text.x = center_hour.x + 7;
                    center_text.y = center_hour.y - 5;
                }
                if (angle <= 90 && angle > 0) { //-- 4
                    center_text.x = center_hour.x - 7;
                    center_text.y = center_hour.y - 10;
                }
                center_text.z = 0;
                //-- Draw Text
                syntext::Text text(
                    label_text,
                    center_text,
                    color,
                    hour_label_deg,
                    scale,
                    false,
                    RK_CLOCK_LABEL_ROTATE
                );
                break;
            }
            //-- Generate Background Points for Minute Label
            case RK_CLOCK_LABEL_MINUTE: {
                //-- Create Polygon Object
                synshape::Polygon polygon;
                //-- Set Center Point
                center_minute.x = RK_CLOCK_WINDOW_WIDTH / 2 + RK_CLOCK_HAND_MINUTE_TEXT_LENGTH * cos(angle * M_PI / 180);
                center_minute.y = RK_CLOCK_WINDOW_HEIGHT / 2 + RK_CLOCK_HAND_MINUTE_TEXT_LENGTH * sin(angle * M_PI / 180);
                center_minute.z = 0;
                center_minute.color = {16, 66, 66, 255};
                //-- Generate Points for Minute Label
                for (int i = 0; i < 60; i++) {
                    double angle = (90 - i * 6) * M_PI / 180;
                    RKGPoint point;
                    point.x = center_minute.x + RK_CLOCK_LABEL_BACKGROUND_RADIUS * cos(angle);
                    point.y = center_minute.y + RK_CLOCK_LABEL_BACKGROUND_RADIUS * sin(angle);
                    point.z = 0;
                    point.color = {14, 24, 24, 255};
                    points.push_back(point);
                }
                //-- Draw Background Circle
                polygon.drawPolygon(points, true);
                //-- Set Minute Label Angle
                minute_label_deg.degree = angle;
                //-- Create Point for Centering Text
                RKGPoint center_text;
                if (angle <= 0 && angle > -90) { //-- 1
                    center_text.x = center_minute.x - 15;
                    center_text.y = center_minute.y - 5;
                }
                if  (angle <= -90 && angle > -180) { //-- 2
                    center_text.x = center_minute.x + 10;
                    center_text.y = center_minute.y + 5;
                }
                if (angle <= -180 && angle > -270) { //-- 3
                    center_text.x = center_minute.x + 7;
                    center_text.y = center_minute.y - 5;
                }
                if (angle <= 90 && angle > 0) { //-- 4
                    center_text.x = center_minute.x - 7;
                    center_text.y = center_minute.y - 10;
                }
                center_text.z = 0;
                //-- Draw Text
                syntext::Text text(
                    label_text,
                    center_text,
                    color,
                    minute_label_deg,
                    scale,
                    false,
                    RK_CLOCK_LABEL_ROTATE
                );
                break;
            }
            //-- Generate Background Points for Second Label
            case RK_CLOCK_LABEL_SECOND: {
                //-- Create Polygon Object
                synshape::Polygon polygon;
                //-- Set Center Point
                center_second.x = RK_CLOCK_WINDOW_WIDTH / 2 + RK_CLOCK_HAND_SECOND_TEXT_LENGTH * cos(angle * M_PI / 180);
                center_second.y = RK_CLOCK_WINDOW_HEIGHT / 2 + RK_CLOCK_HAND_SECOND_TEXT_LENGTH * sin(angle * M_PI / 180);
                center_second.z = 0;
                center_second.color = {16, 66, 66, 255};
                //-- Generate Points for Second Label
                for (int i = 0; i < 60; i++) {
                    double angle = (90 - i * 6) * M_PI / 180;
                    RKGPoint point;
                    point.x = center_second.x + RK_CLOCK_LABEL_BACKGROUND_RADIUS * cos(angle);
                    point.y = center_second.y + RK_CLOCK_LABEL_BACKGROUND_RADIUS * sin(angle);
                    point.z = 0;
                    point.color = {14, 24, 24, 255};
                    points.push_back(point);
                }
                //-- Draw Background Circle
                polygon.drawPolygon(points, true);
                //-- Set Second Label Angle
                second_label_deg.degree = angle;
                //-- Create Point for Centering Text
                RKGPoint center_text;
                if (angle <= 0 && angle > -90) { //-- 1
                    center_text.x = center_second.x - 15;
                    center_text.y = center_second.y - 5;
                }
                if  (angle <= -90 && angle > -180) { //-- 2
                    center_text.x = center_second.x + 10;
                    center_text.y = center_second.y + 5;
                }
                if (angle <= -180 && angle > -270) { //-- 3
                    center_text.x = center_second.x + 7;
                    center_text.y = center_second.y - 5;
                }
                if (angle <= 90 && angle > 0) { //-- 4
                    center_text.x = center_second.x - 7;
                    center_text.y = center_second.y - 10;
                }
                center_text.z = 0;
                //-- Draw Text
                syntext::Text text(
                    label_text,
                    center_text,
                    color,
                    second_label_deg,
                    scale,
                    false,
                    RK_CLOCK_LABEL_ROTATE
                );
                break;
            }
        }
        //-- Return Points
        return points;
    }
    /**
     * @brief Method to Draw Labels
     * @param label Label to Draw
     */
    void RKClock::drawLabels(RKClockLabel label) {
        //-- Handle Label
        switch (label) {
            //-- Draw Hour Labels
            case RK_CLOCK_LABEL_HOUR: {
                //-- Draw Hour Labels
                for (int i = 0; i < 12; i++) {
                    //-- Create Line Object
                    synshape::Line line;
                    //-- Define Line Points
                    RKGPoint point1, point2;
                    point1.x = RK_CLOCK_WINDOW_WIDTH / 2 + RK_CLOCK_RADIUS * 0.96 * cos(i * 30 * M_PI / 180);
                    point1.y = RK_CLOCK_WINDOW_HEIGHT / 2 + RK_CLOCK_RADIUS * 0.96 * sin(i * 30 * M_PI / 180);
                    point1.z = 0;
                    point1.color = {150, 170, 100, 255};
                    point2.x = RK_CLOCK_WINDOW_WIDTH / 2 + RK_CLOCK_RADIUS * 0.87 * cos(i * 30 * M_PI / 180);
                    point2.y = RK_CLOCK_WINDOW_HEIGHT / 2 + RK_CLOCK_RADIUS * 0.87 * sin(i * 30 * M_PI / 180);
                    point2.z = 0;
                    point2.color = {215, 122, 97, 255};
                    //-- Draw Line
                    line.drawLine(point1, point2, 3.0f);
                    // label_deg.degree = i * 30;
                    // syntext::Text text(
                    //     std::to_string(i),
                    //     GLUT_STROKE_ROMAN,
                    //     clk_obt[i],
                    //     {255, 255, 255, 255},
                    //     label_deg,
                    //     {0.2, 0.2, 0.2}
                    // );
                }
                break;
            }
            //-- Draw Minute Labels
            case RK_CLOCK_LABEL_MINUTE: {
                //-- Draw Minute Labels
                for (int i = 0; i < 60; i++) {
                    //-- Create Line Object
                    synshape::Line line;
                    //-- Define Line Points
                    RKGPoint point1, point2;
                    point1.x = RK_CLOCK_WINDOW_WIDTH / 2 + RK_CLOCK_RADIUS * 0.9 * cos(i * 6 * M_PI / 180);
                    point1.y = RK_CLOCK_WINDOW_HEIGHT / 2 + RK_CLOCK_RADIUS * 0.9 * sin(i * 6 * M_PI / 180);
                    point1.z = 0;
                    point1.color = {255, 255, 255, 255};
                    point2.x = RK_CLOCK_WINDOW_WIDTH / 2 + RK_CLOCK_RADIUS * 0.85 * cos(i * 6 * M_PI / 180);
                    point2.y = RK_CLOCK_WINDOW_HEIGHT / 2 + RK_CLOCK_RADIUS * 0.85 * sin(i * 6 * M_PI / 180);
                    point2.z = 0;
                    point2.color = {0, 255, 255, 255};
                    //-- Draw Line
                    line.drawLine(point1, point2, 5.0f);
                }
                break;
            }
            //-- Draw Second Labels
            case RK_CLOCK_LABEL_SECOND: {
                //-- Draw Second Labels
                for (int i = 0; i < 60; i++) {
                    //-- Create Line Object
                    synshape::Line line;
                    //-- Define Line Points
                    RKGPoint point1, point2;
                    point1.x = RK_CLOCK_WINDOW_WIDTH / 2 + RK_CLOCK_RADIUS * 0.95 * cos(i * 6 * M_PI / 180);
                    point1.y = RK_CLOCK_WINDOW_HEIGHT / 2 + RK_CLOCK_RADIUS * 0.95 * sin(i * 6 * M_PI / 180);
                    point1.z = 0;
                    point1.color = {0, 120, 55, 255};
                    point2.x = RK_CLOCK_WINDOW_WIDTH / 2 + RK_CLOCK_RADIUS * 0.9 * cos(i * 6 * M_PI / 180);
                    point2.y = RK_CLOCK_WINDOW_HEIGHT / 2 + RK_CLOCK_RADIUS * 0.9 * sin(i * 6 * M_PI / 180);
                    point2.z = 0;
                    point2.color = {0, 255, 255, 255};
                    //-- Draw Line
                    line.drawLine(point1, point2, 2.0f);
                    // label_deg.degree = i * 6;
                    // syntext::Text text(
                    //     std::to_string(i),
                    //     GLUT_STROKE_ROMAN,
                    //     clk_obt[i],
                    //     {255, 255, 255, 255},
                    //     label_deg,
                    //     {0.2, 0.2, 0.2}
                    // );
                }
                break;
            }
            //-- Draw Millisecond Labels
            case RK_CLOCK_LABEL_MILLISECOND: {
                //-- Draw Millisecond Labels
                for (int i = 0; i < 1000; i++) {
                    if (i % 10 != 0) {
                        continue;
                    }
                    //-- Create Line Object
                    synshape::Line line;
                    //-- Define Line Points
                    RKGPoint point1, point2;
                    point1.x = RK_CLOCK_WINDOW_WIDTH / 2 + RK_CLOCK_RADIUS * 0.97 * cos(i * 0.36 * M_PI / 180);
                    point1.y = RK_CLOCK_WINDOW_HEIGHT / 2 + RK_CLOCK_RADIUS * 0.97 * sin(i * 0.36 * M_PI / 180);
                    point1.z = 0;
                    point1.color = {0, 55, 10, 255};
                    point2.x = RK_CLOCK_WINDOW_WIDTH / 2 + RK_CLOCK_RADIUS * 0.95 * cos(i * 0.36 * M_PI / 180);
                    point2.y = RK_CLOCK_WINDOW_HEIGHT / 2 + RK_CLOCK_RADIUS * 0.95 * sin(i * 0.36 * M_PI / 180);
                    point2.z = 0;
                    point2.color = {0, 120, 55, 255};
                    //-- Draw Line
                    line.drawLine(point1, point2, 2.0f);
                }
                break;
            }
        }
    }
    /**
     * @brief Method to Get Clock Time
     * @param hours Hours
     * @param minutes Minutes
     * @param seconds Seconds
     * @param milliseconds Milliseconds
     */
    void RKClock::getClockTime(int &hours, int &minutes, int &seconds, int &milliseconds) {
        //-- Handle According to UTC or Local Time
        # if RK_CLOCK_SHOW_UTC_TIME
            //-- Get Current Time
            auto now = std::chrono::system_clock::now();
            auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
            auto epoch = now_ms.time_since_epoch();
            auto value = std::chrono::duration_cast<std::chrono::milliseconds>(epoch);
            //-- Get Milliseconds
            milliseconds = value.count() % 1000;
            //-- Get Seconds
            seconds = (value.count() / 1000) % 60;
            //-- Get Minutes
            minutes = (value.count() / (1000 * 60)) % 60;
            //-- Get Hours
            hours = (value.count() / (1000 * 60 * 60)) % 24;
        # else
            //-- Get Current Time
            auto now = std::chrono::system_clock::now();
            auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
            auto epoch = now_ms.time_since_epoch();
            auto value = std::chrono::duration_cast<std::chrono::milliseconds>(epoch);
            //-- Get Milliseconds
            milliseconds = value.count() % 1000;
            //-- Convert to time_t for Local Time Usage
            auto current_time_t = std::chrono::system_clock::to_time_t(now);
            //-- Convert to local time
            std::tm localTime = *std::localtime(&current_time_t);
            //-- Get Seconds
            seconds = localTime.tm_sec;
            //-- Get Minutes
            minutes = localTime.tm_min;
            //-- Get Hours
            hours = localTime.tm_hour;
        # endif // RK_CLOCK_SHOW_UTC_TIME
        std::cout << "\033[2F\033[2K" << RKG_LABEL "Time --> " << hours << ":" << minutes << ":" << seconds << "." << milliseconds << std::endl << std::endl;
    }
    /**
     * @brief Method to Draw Hands
     * @param angle_ms Millisecond Hand Angle
     * @param angle_s Second Hand Angle
     * @param angle_m Minute Hand Angle
     * @param angle_h Hour Hand Angle
     */
    void RKClock::drawHands(
        double angle_ms,
        double angle_s,
        double angle_m,
        double angle_h
    ) {
        //-- Create Line Objects
        synshape::Line line_ms, line_s, line_m, line_h;
        //-- Define Hands Points
        RKGPoint hand_ms1, hand_ms2, hand_s, hand_m, hand_h, hand_center;
        //-- Set Center Point
        hand_center.x = RK_CLOCK_WINDOW_WIDTH / 2;
        hand_center.y = RK_CLOCK_WINDOW_HEIGHT / 2;
        hand_center.z = 0;
        hand_center.color = {0, 205, 225, 255};
        //-- Set Hour Hand Point
        hand_h.x = RK_CLOCK_WINDOW_WIDTH / 2 + RK_CLOCK_HAND_HOUR_LENGTH * cos(angle_h * M_PI / 180);
        hand_h.y = RK_CLOCK_WINDOW_HEIGHT / 2 + RK_CLOCK_HAND_HOUR_LENGTH * sin(angle_h * M_PI / 180);
        hand_h.z = 0;
        hand_h.color = {255, 255, 255, 255};
        //-- Set Minute Hand Point
        hand_m.x = RK_CLOCK_WINDOW_WIDTH / 2 + RK_CLOCK_HAND_MINUTE_LENGTH * cos(angle_m * M_PI / 180);
        hand_m.y = RK_CLOCK_WINDOW_HEIGHT / 2 + RK_CLOCK_HAND_MINUTE_LENGTH * sin(angle_m * M_PI / 180);
        hand_m.z = 0;
        hand_m.color = {255, 255, 255, 255};
        //-- Set Second Hand Point
        hand_s.x = RK_CLOCK_WINDOW_WIDTH / 2 + RK_CLOCK_HAND_SECOND_LENGTH * cos(angle_s * M_PI / 180);
        hand_s.y = RK_CLOCK_WINDOW_HEIGHT / 2 + RK_CLOCK_HAND_SECOND_LENGTH * sin(angle_s * M_PI / 180);
        hand_s.z = 0;
        hand_s.color = {255, 255, 255, 255};
        //-- Draw Hands
        line_h.drawLine(hand_center, hand_h, 2.0f);
        line_m.drawLine(hand_center, hand_m, 2.0f);
        line_s.drawLine(hand_center, hand_s, 2.0f);
        //-- Behave According to Show Milliseconds Mode
        # if RK_CLOCK_HAND_MILLISECOND_SHOW_WITH_POLYGON
            //-- Create Polygon Object
            synshape::Polygon polygon_ms;
            //-- Create Padding Angles for Millisecond Hand
            double angle_ms1 = angle_ms + RK_CLOCK_HAND_MILLISECOND_PADDING_DEGREE;
            double angle_ms2 = angle_ms - RK_CLOCK_HAND_MILLISECOND_PADDING_DEGREE;
            //-- Define Millisecond Hand Points
            RKGPoint hand_ms1_r, hand_ms2_r, hand_ms1_l, hand_ms2_l;
            //-- Set Millisecond Hand Points
            hand_ms1_r.x = RK_CLOCK_WINDOW_WIDTH / 2 + RK_CLOCK_RADIUS * 0.98 * cos(angle_ms1 * M_PI / 180);
            hand_ms1_r.y = RK_CLOCK_WINDOW_HEIGHT / 2 + RK_CLOCK_RADIUS * 0.98 * sin(angle_ms1 * M_PI / 180);
            hand_ms1_r.z = 0;
            hand_ms1_r.color = {0, 50, 22, 255};
            hand_ms2_r.x = RK_CLOCK_WINDOW_WIDTH / 2 + RK_CLOCK_RADIUS * 0.95 * cos(angle_ms1 * M_PI / 180);
            hand_ms2_r.y = RK_CLOCK_WINDOW_HEIGHT / 2 + RK_CLOCK_RADIUS * 0.95 * sin(angle_ms1 * M_PI / 180);
            hand_ms2_r.z = 0;
            hand_ms2_r.color = {0, 50, 22, 255};
            hand_ms1_l.x = RK_CLOCK_WINDOW_WIDTH / 2 + RK_CLOCK_RADIUS * 0.98 * cos(angle_ms2 * M_PI / 180);
            hand_ms1_l.y = RK_CLOCK_WINDOW_HEIGHT / 2 + RK_CLOCK_RADIUS * 0.98 * sin(angle_ms2 * M_PI / 180);
            hand_ms1_l.z = 0;
            hand_ms1_l.color = {0, 255, 22, 255};
            hand_ms2_l.x = RK_CLOCK_WINDOW_WIDTH / 2 + RK_CLOCK_RADIUS * 0.95 * cos(angle_ms2 * M_PI / 180);
            hand_ms2_l.y = RK_CLOCK_WINDOW_HEIGHT / 2 + RK_CLOCK_RADIUS * 0.95 * sin(angle_ms2 * M_PI / 180);
            hand_ms2_l.z = 0;
            hand_ms2_l.color = {0, 255, 22, 255};
            //-- Draw Millisecond Hand
            polygon_ms.drawPolygon({hand_ms1_r, hand_ms2_r, hand_ms2_l, hand_ms1_l}, true);
        # else
            //-- Set Millisecond Hand Points
            hand_ms1.x = RK_CLOCK_WINDOW_WIDTH / 2 + RK_CLOCK_RADIUS * 0.98 * cos(angle_ms * M_PI / 180);
            hand_ms1.y = RK_CLOCK_WINDOW_HEIGHT / 2 + RK_CLOCK_RADIUS * 0.98 * sin(angle_ms * M_PI / 180);
            hand_ms1.z = 0;
            hand_ms1.color = {170, 255, 22, 255};
            hand_ms2.x = RK_CLOCK_WINDOW_WIDTH / 2 + RK_CLOCK_RADIUS * 0.95 * cos(angle_ms * M_PI / 180);
            hand_ms2.y = RK_CLOCK_WINDOW_HEIGHT / 2 + RK_CLOCK_RADIUS * 0.95 * sin(angle_ms * M_PI / 180);
            hand_ms2.z = 0;
            hand_ms2.color = {0, 255, 22, 255};
            line_ms.drawLine(hand_ms1, hand_ms2, 7.0f);
        # endif // RK_CLOCK_HAND_MILLISECOND_SHOW_WITH_POLYGON
    }
    /**
     * @brief Default Constructor
     */
    RKClock::RKClock() {}
    /**
     * @brief Constructor with Clock Type
     * @param type Clock Type
     */
    RKClock::RKClock(RKClockType type) {
        logger(RKG_LABEL INFO "Starting Clock ...");
        //-- Check UTC or Local Time
        # if RK_CLOCK_SHOW_UTC_TIME
            logger(RKG_LABEL INFO "Showing UTC Time ...");
        # else
            logger(RKG_LABEL INFO "Showing Local Time ...");
        # endif // RK_CLOCK_SHOW_UTC_TIME
        //-- Set OpenGL Ortho
        glOrtho(
            0.0, RK_CLOCK_WINDOW_WIDTH,
            0.0, RK_CLOCK_WINDOW_HEIGHT,
            -1.0, 1.0
        );
        //-- Define Clock Time Objects
        int hours, minutes, seconds, milliseconds;
        //-- Handle Clock Type
        switch (type) {
            //-- Test Clock
            case RK_CLOCK_TEST: {
                //-- Window Loop
                while (true) {
                    //-- Clear the Window
                    window.clear(0, 10, 18, 255);
                    //-- Update the Window
                    window.update();
                    //-- Sleep for 20 milliseconds
                    std::this_thread::sleep_for(std::chrono::milliseconds(20));
                }
            }
            //-- Analog Clock
            case RK_CLOCK_ANALOG: {
                //-- Create Queue of Poitns for
                std::deque<RKGPoint> points_milliseconds, points_seconds, points_minutes, points_hours;
                std::deque<RKGPoint> clk_bg, clk_obo, clk_obi, clk_obt, clk_ibo, clk_ibi, clk_ibt, clk_co, clk_ci;
                std::deque<RKGPoint> clk_s, clk_m, clk_h;
                //-- Create Polygon Objects
                synshape::Polygon polygon_ms, polygon_s, polygon_m, polygon_h, polygon_clk;
                //-- Define Hands Angles
                double angle_ms, angle_s, angle_m, angle_h;
                //-- Generate Clock Background Points
                clk_bg = generatePoints(120, RK_CLOCK_RADIUS, {14, 24, 24, 255}, 0, false);
                clk_obo = generatePoints(120, RK_CLOCK_RADIUS * 0.985, {24, 34, 34, 255}, 0, false);
                clk_obi = generatePoints(120, RK_CLOCK_RADIUS * 0.95, {14, 24, 24, 255}, 0, false);
                clk_obt = generatePoints(60, RK_CLOCK_RADIUS * 0.97, {219, 211, 216, 255}, 0, false);
                clk_ibo = generatePoints(120, RK_CLOCK_RADIUS * 0.9, {24, 34, 34, 255}, 0, false);
                clk_ibi = generatePoints(120, RK_CLOCK_RADIUS * 0.8, {14, 24, 24, 255}, 0, false);
                clk_ibt = generatePoints(60, RK_CLOCK_RADIUS * 0.85, {219, 211, 216, 255}, 0, false);
                clk_co = generatePoints(60, RK_CLOCK_RADIUS * 0.06, {16, 66, 66, 255}, 0, false);
                clk_ci = generatePoints(60, RK_CLOCK_RADIUS * 0.045, {24, 34, 34, 255}, 0, false);
                //-- Generate Points for Hours (Not Used)
                points_hours = generatePoints(12, RK_CLOCK_RADIUS * 0.8, {255, 255, 255, 255}, 60, true);
                //-- Generate Points for Minutes (Not Used)
                points_minutes = generatePoints(60, RK_CLOCK_RADIUS * 0.9, {255, 255, 255, 255}, 6, true);
                //-- Window Loop
                while (true) {
                    //-- Clear the Window
                    window.clear(0, 10, 18, 255);
                    //-- Draw Clock Background
                    polygon_clk.drawPolygon(clk_bg, true);
                    polygon_clk.drawPolygon(clk_obo, true);
                    polygon_clk.drawPolygon(clk_obi, true);
                    polygon_clk.drawPolygon(clk_ibo, true);
                    polygon_clk.drawPolygon(clk_ibi, true);
                    polygon_clk.drawPolygon(clk_co, true);
                    //-- Draw Milisecond Labels
                    drawLabels(RK_CLOCK_LABEL_MILLISECOND);
                    //-- Draw Second Labels
                    drawLabels(RK_CLOCK_LABEL_SECOND);
                    //-- Draw Hour Labels
                    drawLabels(RK_CLOCK_LABEL_HOUR);
                    //-- Get Clock Time
                    getClockTime(hours, minutes, seconds, milliseconds);
                    //-- Set Hour Hand Angle
                    angle_h = 90 - ((hours % 12) * 30 + minutes / 2);
                    //-- Set Minute Hand Angle
                    angle_m = 90 - (minutes * 6 + seconds / 10);
                    //-- Set Second Hand Angle
                    angle_s = 90 - (seconds * 6 + milliseconds / 166.6666666667);
                    //-- Set Millisecond Hand Angle
                    angle_ms = 90 - (milliseconds * 0.36);
                    //-- Draw Hands
                    drawHands(angle_ms, angle_s, angle_m, angle_h);
                    //-- Generate Background Circle Points for Labels
                    clk_h = generateBGPoints(RK_CLOCK_LABEL_HOUR, angle_h, std::to_string(hours));
                    clk_m = generateBGPoints(RK_CLOCK_LABEL_MINUTE, angle_m, std::to_string(minutes));
                    clk_s = generateBGPoints(RK_CLOCK_LABEL_SECOND, angle_s, std::to_string(seconds));
                    //-- Draw Center Circle
                    polygon_clk.drawPolygon(clk_ci, true);
                    //-- Update the Window
                    window.update();
                    //-- Sleep for 20 milliseconds
                    std::this_thread::sleep_for(std::chrono::milliseconds(20));
                }
                break;
            }
            //-- Digital Clock
            case RK_CLOCK_DIGITAL: {
                break;
            }
            //-- Modern Clock
            case RK_CLOCK_MODERN: {
                break;
            }
        }
    }
# endif // RK_GRAPHICS_PROJECT_4