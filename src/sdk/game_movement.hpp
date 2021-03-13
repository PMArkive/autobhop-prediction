#pragma once

#include "vector.hpp"

class BasePlayer;
class QAngle;
class GameTrace;
class BaseHandle;
struct MoveData;
enum class IntervalType;

static const char* interface_version_game_movement = "GameMovement001";

class IGameMovement {
public:
    virtual ~IGameMovement();
    virtual void process_movement(BasePlayer* p, MoveData* mv) = 0;
    virtual void start_track_prediction_errors(BasePlayer* p) = 0;
    virtual void finish_track_prediction_errors(BasePlayer* p) = 0;
    virtual void diff_print(const char* fmt, ...) = 0;
    virtual Vector get_player_mins(bool is_ducked) const = 0;
    virtual Vector get_player_maxs(bool is_ducked) const = 0;
    virtual Vector get_player_view_offset(bool is_ducked) const = 0;
};

class GameMovement : public IGameMovement {
public:
    virtual void trace_player_bbox(const Vector& start, const Vector& end, unsigned mask, int collision_group, GameTrace& tr);
    virtual void try_touch_ground(const Vector& start, const Vector& end, const Vector& mins, const Vector& maxs, unsigned mask, int collision_group, GameTrace& tr);
    virtual unsigned player_solid_mask(bool brush_only=false);
    virtual void player_move();
    virtual float calc_roll(const QAngle& angles, const Vector& vel, float roll_angle, float roll_speed);
    virtual void decay_punch_angle();
    virtual void check_water_jump();
    virtual void water_move();
    virtual void air_accelerate(Vector& wish_dir, float wish_speed, float accel);
    virtual void air_move();
    virtual float get_air_speed_cap();
    virtual bool can_accelerate();
    virtual void accelerate(Vector& wish_dir, float wish_speed, float accel);
    virtual void walk_move();
    virtual void full_walk_move();
    virtual void on_jump();
    virtual void on_land();
    virtual void on_try_player_move_collision(GameTrace& tr);
    virtual Vector get_player_mins() const;
    virtual Vector get_player_maxs() const;
    virtual int get_check_interval(IntervalType t);
    virtual bool check_jump_button();
    virtual void full_toss_move();
    virtual void full_ladder_move();
    virtual int try_player_move(Vector* first_dest=nullptr, GameTrace* first_trace=nullptr);
    virtual bool ladder_move();
    virtual bool on_ladder(GameTrace& tr);
    virtual float ladder_distance() const;
    virtual unsigned ladder_mask() const;
    virtual float climb_speed() const;
    virtual float ladder_lateral_multiplier() const;
    virtual int check_stuck();
    virtual bool check_water();
    virtual void categorize_position();
    virtual void check_parameters();
    virtual void reduce_timers();
    virtual void check_falling();
    virtual void player_rough_landing_effects();
    virtual void duck();
    virtual void handle_ducking_speed_crop();
    virtual void finish_unduck();
    virtual void finish_duck();
    virtual bool can_unduck();
    virtual BaseHandle test_player_position(const Vector& pos, int collision_group, GameTrace& tr);
    virtual void set_ground_entity(GameTrace& tr);
    virtual void setup_move(Vector& dest, GameTrace& tr);
    virtual bool game_has_ladders() const;

    BasePlayer* player;
    MoveData* move_data;
    int old_water_level;
    int water_entry_time;
    int ladder;
    Vector forward;
    Vector right;
    Vector up;
    int cached_get_point_contents[65][3];
    Vector cached_get_point_contents_point[65][3];
    Vector proximity_mins;
    Vector proximity_maxs;
    float frame_time;
    int speed_cropped;
    float stuck_check_time[65 + 1][2];
};
