#include <addons.h>

void MultiTaskThreadStaging_setup() {
    ecs_log_set_level(-3);
}

static
void MultiTaskThread_Add_to_current(ecs_iter_t *it) {
    IterData *ctx = ecs_get_context(it->world);

    int i;
    for (i = 0; i < it->count; i ++) {
        if (ctx->component) {
            ecs_add_id(it->world, it->entities[i], ctx->component);
        }

        if (ctx->component_2) {
            ecs_add_id(it->world, it->entities[i], ctx->component_2);
        }

        ctx->entity_count ++;
    }
}

void MultiTaskThreadStaging_2_threads_add_to_current() {
    ecs_world_t *world = ecs_init();

    ECS_COMPONENT(world, Position);
    ECS_COMPONENT(world, Velocity);
    ECS_COMPONENT(world, Rotation);
    ECS_PREFAB(world, Type, Position, Velocity);

    ECS_SYSTEM(world, MultiTaskThread_Add_to_current, EcsOnUpdate, Position);

    ecs_system_init(world, &(ecs_system_desc_t){
        .entity = MultiTaskThread_Add_to_current,
        .multi_threaded = true
    });

    IterData ctx = {.component = ecs_id(Rotation)};
    ecs_set_context(world, &ctx);

    ecs_entity_t ids_1[100];
    const ecs_entity_t *temp_ids_1 = ecs_bulk_new(world, Position, 100);
    memcpy(ids_1, temp_ids_1, sizeof(ecs_entity_t) * 100);

    const ecs_entity_t *ids_2 = bulk_new_w_type(world, Type, 100);

    ecs_set_task_threads(world, 2, ecs_os_api.thread_new_, ecs_os_api.thread_join_);

    ecs_progress(world, 1);

    int i;
    for (i = 0; i < 100; i ++) {
        test_assert( ecs_has(world, ids_1[i], Position));
        test_assert( ecs_has(world, ids_1[i], Rotation));
        test_assert( !ecs_has(world, ids_1[i], Velocity));
    }

    for (i = 0; i < 100; i ++) {
        test_assert( ecs_has(world, ids_2[i], Position));
        test_assert( ecs_has(world, ids_2[i], Rotation));
        test_assert( ecs_has(world, ids_2[i], Velocity));
    }

    ecs_fini(world);
}

void MultiTaskThreadStaging_3_threads_add_to_current() {
    ecs_world_t *world = ecs_init();

    ECS_COMPONENT(world, Position);
    ECS_COMPONENT(world, Velocity);
    ECS_COMPONENT(world, Rotation);
    ECS_PREFAB(world, Type, Position, Velocity);

    ECS_SYSTEM(world, MultiTaskThread_Add_to_current, EcsOnUpdate, Position);

    ecs_system_init(world, &(ecs_system_desc_t){
        .entity = MultiTaskThread_Add_to_current,
        .multi_threaded = true
    });

    IterData ctx = {.component = ecs_id(Rotation)};
    ecs_set_context(world, &ctx);

    ecs_entity_t ids_1[100];
    const ecs_entity_t *temp_ids_1 = ecs_bulk_new(world, Position, 100);
    memcpy(ids_1, temp_ids_1, sizeof(ecs_entity_t) * 100);

    const ecs_entity_t *ids_2 = bulk_new_w_type(world, Type, 100);

    ecs_set_task_threads(world, 3, ecs_os_api.thread_new_, ecs_os_api.thread_join_);

    ecs_progress(world, 1);

    int i;
    for (i = 0; i < 100; i ++) {
        test_assert( ecs_has(world, ids_1[i], Position));
        test_assert( ecs_has(world, ids_1[i], Rotation));
        test_assert( !ecs_has(world, ids_1[i], Velocity));
    }

    for (i = 0; i < 100; i ++) {
        test_assert( ecs_has(world, ids_2[i], Position));
        test_assert( ecs_has(world, ids_2[i], Rotation));
        test_assert( ecs_has(world, ids_2[i], Velocity));
    }

    ecs_fini(world);
}

void MultiTaskThreadStaging_4_threads_add_to_current() {
    ecs_world_t *world = ecs_init();

    ECS_COMPONENT(world, Position);
    ECS_COMPONENT(world, Velocity);
    ECS_COMPONENT(world, Rotation);
    ECS_PREFAB(world, Type, Position, Velocity);

    ECS_SYSTEM(world, MultiTaskThread_Add_to_current, EcsOnUpdate, Position);

    ecs_system_init(world, &(ecs_system_desc_t){
        .entity = MultiTaskThread_Add_to_current,
        .multi_threaded = true
    });

    IterData ctx = {.component = ecs_id(Rotation)};
    ecs_set_context(world, &ctx);

    ecs_entity_t ids_1[100];
    const ecs_entity_t *temp_ids_1 = ecs_bulk_new(world, Position, 100);
    memcpy(ids_1, temp_ids_1, sizeof(ecs_entity_t) * 100);

    const ecs_entity_t *ids_2 = bulk_new_w_type(world, Type, 100);

    ecs_set_task_threads(world, 4, ecs_os_api.thread_new_, ecs_os_api.thread_join_);

    ecs_progress(world, 1);

    int i;
    for (i = 0; i < 100; i ++) {
        test_assert( ecs_has(world, ids_1[i], Position));
        test_assert( ecs_has(world, ids_1[i], Rotation));
        test_assert( !ecs_has(world, ids_1[i], Velocity));
    }

    for (i = 0; i < 100; i ++) {
        test_assert( ecs_has(world, ids_2[i], Position));
        test_assert( ecs_has(world, ids_2[i], Rotation));
        test_assert( ecs_has(world, ids_2[i], Velocity));
    }

    ecs_fini(world);
}

void MultiTaskThreadStaging_5_threads_add_to_current() {
    ecs_world_t *world = ecs_init();

    ECS_COMPONENT(world, Position);
    ECS_COMPONENT(world, Velocity);
    ECS_COMPONENT(world, Rotation);
    ECS_PREFAB(world, Type, Position, Velocity);

    ECS_SYSTEM(world, MultiTaskThread_Add_to_current, EcsOnUpdate, Position);

    ecs_system_init(world, &(ecs_system_desc_t){
        .entity = MultiTaskThread_Add_to_current,
        .multi_threaded = true
    });

    IterData ctx = {.component = ecs_id(Rotation)};
    ecs_set_context(world, &ctx);

    ecs_entity_t ids_1[100];
    const ecs_entity_t *temp_ids_1 = ecs_bulk_new(world, Position, 100);
    memcpy(ids_1, temp_ids_1, sizeof(ecs_entity_t) * 100);

    const ecs_entity_t *ids_2 = bulk_new_w_type(world, Type, 100);

    ecs_set_task_threads(world, 5, ecs_os_api.thread_new_, ecs_os_api.thread_join_);

    ecs_progress(world, 1);

    int i;
    for (i = 0; i < 100; i ++) {
        test_assert( ecs_has(world, ids_1[i], Position));
        test_assert( ecs_has(world, ids_1[i], Rotation));
        test_assert( !ecs_has(world, ids_1[i], Velocity));
    }

    for (i = 0; i < 100; i ++) {
        test_assert( ecs_has(world, ids_2[i], Position));
        test_assert( ecs_has(world, ids_2[i], Rotation));
        test_assert( ecs_has(world, ids_2[i], Velocity));
    }

    ecs_fini(world);
}

void MultiTaskThreadStaging_6_threads_add_to_current() {
    ecs_world_t *world = ecs_init();

    ECS_COMPONENT(world, Position);
    ECS_COMPONENT(world, Velocity);
    ECS_COMPONENT(world, Rotation);
    ECS_PREFAB(world, Type, Position, Velocity);

    ECS_SYSTEM(world, MultiTaskThread_Add_to_current, EcsOnUpdate, Position);

    ecs_system_init(world, &(ecs_system_desc_t){
        .entity = MultiTaskThread_Add_to_current,
        .multi_threaded = true
    });

    IterData ctx = {.component = ecs_id(Rotation)};
    ecs_set_context(world, &ctx);

    ecs_entity_t ids_1[100];
    const ecs_entity_t *temp_ids_1 = ecs_bulk_new(world, Position, 100);
    memcpy(ids_1, temp_ids_1, sizeof(ecs_entity_t) * 100);

    const ecs_entity_t *ids_2 = bulk_new_w_type(world, Type, 100);

    ecs_set_task_threads(world, 6, ecs_os_api.thread_new_, ecs_os_api.thread_join_);

    ecs_progress(world, 1);

    int i;
    for (i = 0; i < 100; i ++) {
        test_assert( ecs_has(world, ids_1[i], Position));
        test_assert( ecs_has(world, ids_1[i], Rotation));
        test_assert( !ecs_has(world, ids_1[i], Velocity));
    }

    for (i = 0; i < 100; i ++) {
        test_assert( ecs_has(world, ids_2[i], Position));
        test_assert( ecs_has(world, ids_2[i], Rotation));
        test_assert( ecs_has(world, ids_2[i], Velocity));
    }

    ecs_fini(world);
}

static
void InitVelocity(ecs_iter_t *it) {
    Velocity *v = ecs_field(it, Velocity, 1);

    int i;
    for (i = 0; i < it->count; i ++) {
        v[i].x = 10;
        v[i].y = 20;
    }
}

static
void AddVelocity(ecs_iter_t *it) {
    ecs_id_t ecs_id(Velocity) = ecs_field_id(it, 2);

    int i;
    for (i = 0; i < it->count; i ++) {
        ecs_add(it->world, it->entities[i], Velocity);
    }
}

void MultiTaskThreadStaging_2_threads_on_add() {
    ecs_world_t *world = ecs_init();

    ECS_COMPONENT(world, Position);
    ECS_COMPONENT(world, Velocity);

    ECS_OBSERVER(world, InitVelocity, EcsOnAdd, Velocity);
    ECS_SYSTEM(world, AddVelocity, EcsOnUpdate, Position, Velocity());

    ecs_system_init(world, &(ecs_system_desc_t){
        .entity = AddVelocity,
        .multi_threaded = true
    });

    Probe ctx = {0};
    ecs_set_context(world, &ctx);

    const ecs_entity_t *ids = ecs_bulk_new(world, Position, 10);
    test_assert(ids != NULL);

    ecs_set_task_threads(world, 2, ecs_os_api.thread_new_, ecs_os_api.thread_join_);

    ecs_progress(world, 0);

    int i;
    for (i = 0; i < 10; i ++) {
        ecs_entity_t e = ids[i];
        test_assert( ecs_has(world, e, Velocity));
        const Velocity *v = ecs_get(world, e, Velocity);
        test_assert(v != NULL);
        test_int(v->x, 10);
        test_int(v->y, 20);
    }

    ecs_fini(world);
}

static
void New_w_count(ecs_iter_t *it) {
    ecs_id_t ecs_id(Position) = ecs_field_id(it, 1);

    ecs_bulk_new(it->world, Position, 10);
}

void MultiTaskThreadStaging_new_w_count() {
    ecs_world_t *world = ecs_init();

    ECS_COMPONENT(world, Position);

    ECS_SYSTEM(world, New_w_count, EcsOnUpdate, Position());

    ecs_system_init(world, &(ecs_system_desc_t){
        .entity = New_w_count,
        .multi_threaded = true
    });

    ecs_set_task_threads(world, 2, ecs_os_api.thread_new_, ecs_os_api.thread_join_);

    ecs_progress(world, 0);

    test_int( ecs_count(world, Position), 10);

    ecs_fini(world);
}

void MultiTaskThreadStaging_custom_thread_auto_merge() {
    ecs_world_t *world = ecs_init();

    ECS_COMPONENT(world, Position);

    ecs_entity_t e1 = ecs_new_id(world);
    ecs_entity_t e2 = ecs_new_id(world);

    ecs_set_stage_count(world, 2);

    ecs_world_t *ctx_1 = ecs_get_stage(world, 0);
    ecs_world_t *ctx_2 = ecs_get_stage(world, 1);

    ecs_frame_begin(world, 0);
    ecs_readonly_begin(world);

    /* thread 1 */
    ecs_defer_begin(ctx_1);
    ecs_set(ctx_1, e1, Position, {10, 20});
    test_assert(!ecs_has(world, e1, Position));
    test_assert(!ecs_has(ctx_1, e1, Position));
    ecs_defer_end(ctx_1);
    test_assert(!ecs_has(world, e1, Position));
    test_assert(!ecs_has(ctx_1, e1, Position));
    
    /* thread 2 */
    ecs_defer_begin(ctx_2);
    ecs_set(ctx_2, e2, Position, {20, 30});
    test_assert(!ecs_has(world, e2, Position));
    test_assert(!ecs_has(ctx_2, e2, Position));
    ecs_defer_end(ctx_2);
    test_assert(!ecs_has(world, e2, Position));
    test_assert(!ecs_has(ctx_2, e2, Position));

    ecs_readonly_end(world);
    ecs_frame_end(world);

    test_assert(ecs_has(world, e1, Position));
    test_assert(ecs_has(world, e2, Position));

    const Position *p1 = ecs_get(world, e1, Position);
    test_int(p1->x, 10);
    test_int(p1->y, 20);

    const Position *p2 = ecs_get(world, e2, Position);
    test_int(p2->x, 20);
    test_int(p2->y, 30);    

    ecs_fini(world);
}

void MultiTaskThreadStaging_custom_thread_manual_merge() {
    ecs_world_t *world = ecs_init();

    ECS_COMPONENT(world, Position);

    ecs_entity_t e1 = ecs_new_id(world);
    ecs_entity_t e2 = ecs_new_id(world);

    ecs_set_automerge(world, false);

    ecs_set_stage_count(world, 2);

    ecs_world_t *ctx_1 = ecs_get_stage(world, 0);
    ecs_world_t *ctx_2 = ecs_get_stage(world, 1);

    ecs_frame_begin(world, 0);
    ecs_readonly_begin(world);

    /* thread 1 */
    ecs_defer_begin(ctx_1);
    ecs_set(ctx_1, e1, Position, {10, 20});
    test_assert(!ecs_has(world, e1, Position));
    test_assert(!ecs_has(ctx_1, e1, Position));
    ecs_defer_end(ctx_1);
    test_assert(!ecs_has(world, e1, Position));
    test_assert(!ecs_has(ctx_1, e1, Position));
    
    /* thread 2 */
    ecs_defer_begin(ctx_2);
    ecs_set(ctx_2, e2, Position, {20, 30});
    test_assert(!ecs_has(world, e2, Position));
    test_assert(!ecs_has(ctx_2, e2, Position));
    ecs_defer_end(ctx_2);
    test_assert(!ecs_has(world, e2, Position));
    test_assert(!ecs_has(ctx_2, e2, Position));

    ecs_readonly_end(world);
    ecs_frame_end(world);

    test_assert(!ecs_has(world, e1, Position));
    test_assert(!ecs_has(world, e2, Position));

    ecs_merge(world);

    test_assert(ecs_has(world, e1, Position));
    test_assert(ecs_has(world, e2, Position));

    const Position *p1 = ecs_get(world, e1, Position);
    test_int(p1->x, 10);
    test_int(p1->y, 20);

    const Position *p2 = ecs_get(world, e2, Position);
    test_int(p2->x, 20);
    test_int(p2->y, 30);    

    ecs_fini(world);
}

void MultiTaskThreadStaging_custom_thread_partial_manual_merge() {
    ecs_world_t *world = ecs_init();

    ECS_COMPONENT(world, Position);

    ecs_entity_t e1 = ecs_new_id(world);
    ecs_entity_t e2 = ecs_new_id(world);

    ecs_set_stage_count(world, 2);

    ecs_world_t *ctx_1 = ecs_get_stage(world, 0);
    ecs_world_t *ctx_2 = ecs_get_stage(world, 1);

    /* Only disable automerging for ctx_2 */
    ecs_set_automerge(ctx_2, false);

    ecs_frame_begin(world, 0);
    ecs_readonly_begin(world);

    /* thread 1 */
    ecs_defer_begin(ctx_1);
    ecs_set(ctx_1, e1, Position, {10, 20});
    test_assert(!ecs_has(world, e1, Position));
    test_assert(!ecs_has(ctx_1, e1, Position));
    ecs_defer_end(ctx_1);
    test_assert(!ecs_has(world, e1, Position));
    test_assert(!ecs_has(ctx_1, e1, Position));
    
    /* thread 2 */
    ecs_defer_begin(ctx_2);
    ecs_set(ctx_2, e2, Position, {20, 30});
    test_assert(!ecs_has(world, e2, Position));
    test_assert(!ecs_has(ctx_2, e2, Position));
    ecs_defer_end(ctx_2);
    test_assert(!ecs_has(world, e2, Position));
    test_assert(!ecs_has(ctx_2, e2, Position));

    ecs_readonly_end(world);
    ecs_frame_end(world);

    test_assert(ecs_has(world, e1, Position));
    test_assert(!ecs_has(world, e2, Position));

    const Position *p1 = ecs_get(world, e1, Position);
    test_int(p1->x, 10);
    test_int(p1->y, 20);    

    ecs_merge(ctx_2);

    test_assert(ecs_has(world, e1, Position));
    test_assert(ecs_has(world, e2, Position));

    p1 = ecs_get(world, e1, Position);
    test_int(p1->x, 10);
    test_int(p1->y, 20);

    const Position *p2 = ecs_get(world, e2, Position);
    test_int(p2->x, 20);
    test_int(p2->y, 30);    

    ecs_fini(world);
}

void MultiTaskThreadStaging_set_pair_w_new_target_readonly() {
    ecs_world_t *world = ecs_init();

    ECS_COMPONENT(world, Position);

    ecs_set_task_threads(world, 2, ecs_os_api.thread_new_, ecs_os_api.thread_join_);

    ecs_entity_t e = ecs_new_id(world);

    ecs_world_t *thr_1 = ecs_get_stage(world, 0);

    ecs_frame_begin(world, 0);
    ecs_readonly_begin(world);

    ecs_entity_t tgt = ecs_new_id(thr_1);
    ecs_set_pair(thr_1, e, Position, tgt, {10, 20});

    ecs_readonly_end(world);
    ecs_frame_end(world);

    test_assert(ecs_has_pair(world, e, ecs_id(Position), tgt));

    const Position *p = ecs_get_pair(world, e, Position, tgt);
    test_assert(p != NULL);
    test_int(p->x, 10);
    test_int(p->y, 20);

    ecs_fini(world);
}

void MultiTaskThreadStaging_set_pair_w_new_target_tgt_component_readonly() {
    ecs_world_t *world = ecs_init();

    ECS_COMPONENT(world, Position);

    ecs_set_task_threads(world, 2, ecs_os_api.thread_new_, ecs_os_api.thread_join_);

    ecs_entity_t e = ecs_new_id(world);

    ecs_world_t *thr_1 = ecs_get_stage(world, 0);

    ecs_frame_begin(world, 0);
    ecs_readonly_begin(world);

    ecs_entity_t tgt = ecs_new_id(thr_1);
    ecs_set_pair_second(thr_1, e, tgt, Position, {10, 20});

    ecs_readonly_end(world);
    ecs_frame_end(world);

    test_assert(ecs_has_pair(world, e, tgt, ecs_id(Position)));

    const Position *p = ecs_get_pair_second(world, e, tgt, Position);
    test_assert(p != NULL);
    test_int(p->x, 10);
    test_int(p->y, 20);

    ecs_fini(world);
}

void MultiTaskThreadStaging_set_pair_w_new_target_defer() {
    ecs_world_t *world = ecs_init();

    ECS_COMPONENT(world, Position);

    ecs_set_task_threads(world, 2, ecs_os_api.thread_new_, ecs_os_api.thread_join_);

    ecs_entity_t e = ecs_new_id(world);

    ecs_defer_begin(world);

    ecs_entity_t tgt = ecs_new_id(world);
    ecs_set_pair(world, e, Position, tgt, {10, 20});

    ecs_defer_end(world);

    test_assert(ecs_has_pair(world, e, ecs_id(Position), tgt));

    const Position *p = ecs_get_pair(world, e, Position, tgt);
    test_assert(p != NULL);
    test_int(p->x, 10);
    test_int(p->y, 20);

    ecs_fini(world);
}

void MultiTaskThreadStaging_set_pair_w_new_target_tgt_component_defer() {
    ecs_world_t *world = ecs_init();

    ECS_COMPONENT(world, Position);

    ecs_set_task_threads(world, 2, ecs_os_api.thread_new_, ecs_os_api.thread_join_);

    ecs_entity_t e = ecs_new_id(world);

    ecs_defer_begin(world);

    ecs_entity_t tgt = ecs_new_id(world);
    ecs_set_pair_second(world, e, tgt, Position, {10, 20});

    ecs_defer_end(world);

    test_assert(ecs_has_pair(world, e, tgt, ecs_id(Position)));

    const Position *p = ecs_get_pair_second(world, e, tgt, Position);
    test_assert(p != NULL);
    test_int(p->x, 10);
    test_int(p->y, 20);

    ecs_fini(world);
}
