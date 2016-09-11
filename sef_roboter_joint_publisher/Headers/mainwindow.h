#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include "trajectory_msgs/JointTrajectory.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(ros::NodeHandle *nh);
    ~MainWindow();

private slots:
    void on_button_move_to_home_clicked();
    void on_button_move_to_slider_goal_clicked();
    void on_button_move_to_spinbox_goal_clicked();
    void on_slider_joint_1_valueChanged(int value);
    void on_slider_joint_2_valueChanged(int value);
    void on_slider_joint_3_valueChanged(int value);
    void on_slider_joint_4_valueChanged(int value);
    void on_slider_joint_5_valueChanged(int value);
    void on_slider_joint_6_valueChanged(int value);
    void on_spinbox_joint_1_valueChanged(double arg1);
    void on_spinbox_joint_2_valueChanged(double arg1);
    void on_spinbox_joint_3_valueChanged(double arg1);
    void on_spinbox_joint_4_valueChanged(double arg1);
    void on_spinbox_joint_5_valueChanged(double arg1);
    void on_spinbox_joint_6_valueChanged(double arg1);
    void on_spinbox_slider_duration_valueChanged(int arg1);
    void on_spinbox_spinbox_duration_valueChanged(int arg1);

private:
    void jointStateCallback(const sensor_msgs::JointStateConstPtr &msg);

    Ui::MainWindow *ui;

    ros::NodeHandle *nh;
    ros::Subscriber sub_joint_states;
    ros::Publisher pub_joint_trajectory;

    int timer_id;

    std::vector<double> slider_goals;
    int slider_trajectory_duration;

    std::vector<double> spinbox_goals;
    int spinbox_trajectory_duration;

    static const int NUM_OF_JOINTS = 6;
    static const int HOMING_TIME = 10;

protected:
    void timerEvent(QTimerEvent *timer_event);

};

#endif // MAINWINDOW_H
